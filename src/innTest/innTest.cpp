/*
 * ====================== innTest.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.01.01
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 */
#include "innTest.h"
#include "pch.h"

//------------------- Libs --------------------//
#include "magic_enum.hpp"

//------------------- Engine --------------------//
#include "DirAxes.h"
#include "DyBinary.h"
#include "History.h"

#include "random.h"
#include "simplexNoise.h"

#include "NineDirection.h"

#include "RGBA.h"

namespace innTest { //---------- namespace: innTest --------------//

void innTest_main()
{

    return;
    tprDebug::console("\n~~~~~~~~~~ innTest:start ~~~~~~~~~~\n");

    RGBA color{ 11, 22, 33, 44 };

    tprDebug::console(color.to_string());

    tprDebug::console("\n\n~~~~~~~~~~ innTest:end ~~~~~~~~~~");
}

} //-------------------- namespace: innTest end --------------//
