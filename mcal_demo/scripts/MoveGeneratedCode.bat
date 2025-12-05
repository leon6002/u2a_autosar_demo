@echo off
echo Moving Can_Cfg.h...
move /Y "D:\isoft\demo\mcal_demo\output\can\include\Can_Cfg.h" "D:\isoft\demo\ghs_demo\BSW\Config\MCAL_Config\include\Can_Cfg.h"

echo Moving Can_Lcfg.c...
move /Y "D:\isoft\demo\mcal_demo\output\can\src\Can_Lcfg.c" "D:\isoft\demo\ghs_demo\BSW\Config\MCAL_Config\src\Can_Lcfg.c"

echo Moving Can_PBcfg.c...
move /Y "D:\isoft\demo\mcal_demo\output\can\src\Can_PBcfg.c" "D:\isoft\demo\ghs_demo\BSW\Config\MCAL_Config\src\Can_PBcfg.c"

echo Done.
pause
