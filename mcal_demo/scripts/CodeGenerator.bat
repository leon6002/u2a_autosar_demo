@rem Support:
@rem     chaoyang.ren.aj@renesas.com
@rem Version: 
@rem     2018/12/20  Create
@rem Description:
@rem     Generate source code with configured files

@echo off

@rem @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@rem The following parameters are configurable, please configure according to your needs.
@rem @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

@rem UsrAllModules modules=adc,can,dio,eth,fls,fr,gpt,icu,lin,mcu,port,pwm,spi,wdg
set UsrAllModules=adc,can,dio,eth,fls,fr,gpt,icu,lin,mcu,port,pwm,spi,wdg

@REM set CHIP_TYPE=U2A16
set CHIP_TYPE=U2A16

@rem Back to the root directory
cd ..

@rem Set global variables for use
set RootDir=%cd%

set PRJ_DIR=%cd%\X2x\modules

@REM set ARXML_DIR=F:\davinci\project\U2A_R7F702300EABA_V43.03.00_test\Config\ECUC
@REM set ARXML_NAME=U2A_R7F702300EABA_V43_03_00_test.ecuc.arxml
set ARXML_DIR=%cd%\Config\ECUC
set ARXML_NAME=Demo_U2A16_MCAL_ASR431_V430300_ConfigProject.ecuc.arxml

set OUTPUT_DIR=%cd%\output

@rem @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@rem The following is the code, if you don't know what it is, please don't modify it.
@rem @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

@rem Add or remove the modules you need here
set modules=adc,can,dio,eth,fls,fr,gpt,icu,lin,mcu,port,pwm,spi,wdg
set pascalmodules=Adc,Can,Dio,Ech,Fls,Fr,Gpt,Icu,Lin,Mcu,Port,Pwm,Spi,Wdg
set demmodules=Adc,Can,Eth,Fr,Gpt,Icu,Lin,Mcu,Port,Pwm,Spi,Wdg
set ecummodules=Can,Gpt,Icu,Lin
set osmodules=Can,Eth

set MCALGenerator=%RootDir%\X2x\common\generic\generator\MCALConfGen.exe
set DemDir=%RootDir%\X2x\common\generic\stubs\4_3_1\Dem\xml
set EcumDir=%RootDir%\X2x\common\generic\stubs\4_3_1\EcuM\xml
set CfgTrxml=%RootDir%\scripts\Sample_Application_U2Ax.trxml
set OsDir=%RootDir%\X2x\common\generic\stubs\4_3_1\Os\xml
set FRIF=%RootDir%\X2x\common\generic\stubs\4_3_1\FrIf\xml\FrIf.arxml
set FRIF_MULTI=%RootDir%\X2x\common\generic\stubs\4_3_1\FrIf\xml\FrIf_MultiCtrl.arxml
set "BswMd="
set "CurModule="
set "UpperMod="
set "DemConfig="
set "EcumConfig="
set "OsConfig="

set "UsrInputModules=%1%"

:start_work
@rem Loop generates all the code selected
for %%i in (%UsrInputModules%) do (

    @rem Get the relative path of the BSWMD file
    for %%j in (%RootDir%\X2x\modules\%%i\generator\%CHIP_TYPE%\*.arxml) do (
        set "BswMd=%%j"
    )

    set "CurModule=%%i"

    @rem Find the configuration file of the Dem module
    call:find_dem_mod 
    call:set_dem_config

    call:find_ecum_mod
    call:set_ecum_config

    call:find_os_mod
    call:set_os_config

    @rem Call the command to generate code
    call:generate_code 

)

exit

:find_dem_mod
@rem Find the configuration file of the Dem module
set "UpperMod="
for %%m in (%demmodules%) do (

    if /i %%m == %CurModule% (
        set "UpperMod=%%m"
    )
)
goto :eof

:set_dem_config
@rem set the configuration file of the Dem module
if defined UpperMod (

    set "DemConfig="%DemDir%\\"Dem_"%UpperMod%".arxml"""
) else (

    set "DemConfig="
)
goto :eof

:find_ecum_mod
@rem Find the configuration file of the EcuM module
set "UpperMod="
for %%m in (%ecummodules%) do (

    if /i %%m == %CurModule% (
        set "UpperMod=%%m"
    )
)
goto :eof

:set_ecum_config
@rem set the configuration file of the EcuM module
if defined UpperMod (

    set "EcumConfig="%EcumDir%\\"EcuM_"%UpperMod%".arxml"""
) else (

    set "EcumConfig="
)
goto :eof

:find_os_mod
@rem Find the configuration file of the Os module
set "UpperMod="
for %%m in (%osmodules%) do (

    if /i %%m == %CurModule% (
        set "UpperMod=%%m"
    )
)
goto :eof

:set_os_config
@rem set the configuration file of the Os module
if defined UpperMod (

    set "OsConfig="%OsDir%\\"Os_"%UpperMod%".arxml"""
) else (

    set "OsConfig="
)
goto :eof

:generate_code
@rem Generate code
if "%CurModule%" == "fr" (
    %MCALGenerator% -m %CurModule% -O %OUTPUT_DIR%\%CurModule% %ARXML_DIR%\%ARXML_NAME% %CfgTrxml% %BswMd% %DemConfig% %EcumConfig% %OsConfig% %FRIF% %FRIF_MULTI%
) else (
    %MCALGenerator% -m %CurModule% -O %OUTPUT_DIR%\%CurModule% %ARXML_DIR%\%ARXML_NAME% %CfgTrxml% %BswMd% %DemConfig% %EcumConfig% %OsConfig%
)
set "UpperMod="
goto :eof  