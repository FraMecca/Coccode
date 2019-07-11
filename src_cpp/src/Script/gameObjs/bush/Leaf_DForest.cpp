/*
 * ================== Leaf_DForest.cpp ==================
 *                          -- tpr --
 *                                        CREATE -- 2019.04.10
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 */
#include "Script/gameObjs/bush/Leaf_DForest.h"

//-------------------- C --------------------//
#include <cmath>

//-------------------- CPP --------------------//
#include <functional>
#include <string>

//-------------------- tpr --------------------//
#include "tprGeneral.h"

//-------------------- Engine --------------------//
#include "tprAssert.h"
#include "esrc_shader.h" 

//-------------------- Script --------------------//
#include "Script/resource/ssrc.h" 
#include "Script/gameObjs/create_go_oth.h"

using namespace std::placeholders;

#include "tprDebug.h" 


namespace gameObjs{//------------- namespace gameObjs ----------------



/* ===========================================================
 *                    init_in_autoMod
 * -----------------------------------------------------------
 */
void Leaf_DForest::init_in_autoMod(   goSpecId_t specID_,
                                GameObj &goRef_,
					            double fieldWeight_,
					            const MapAltitude &alti_,
					            const Density &_density ){

    //================ go.pvtBinary =================//
    goRef_.resize_pvtBinary( sizeof(Leaf_DForest_PvtBinary) );
    Leaf_DForest_PvtBinary  *pvtBp = reinterpret_cast<Leaf_DForest_PvtBinary*>(goRef_.get_pvtBinaryPtr());

        pvtBp->leaf_DForestId = gameObjs::apply_a_simpleId( fieldWeight_, 8 );

    //================ animFrameSet／animFrameIdxHandle/ goMesh =================//
        //------- 制作 mesh 实例: "root" -------
        goRef_.creat_new_goMesh("root", //- gmesh-name
                                "leaf_DForest", 
                                tprGeneral::nameString_combine("", pvtBp->leaf_DForestId, "_idle"),
                                RenderLayerType::MajorGoes, //- 不设置 固定zOff值
                                &esrc::get_rect_shader(),  
                                &esrc::get_rect_shader(), //- 其实没有 shadow
                                glm::vec2{ 0.0f, 0.0f }, //- pposoff
                                0.0,  //- off_z
                                true, //- isVisible
                                true, //- isCollide
                                gameObjs::apply_isFlipOver( fieldWeight_ ) //- isFlipOver
                                );

    //================ bind callback funcs =================//
    //-- 故意将 首参数this 绑定到 保留类实例 dog_a 身上
    goRef_.RenderUpdate = std::bind( &Leaf_DForest::OnRenderUpdate, _1 );   
    goRef_.LogicUpdate  = std::bind( &Leaf_DForest::OnLogicUpdate,  _1 );
    
    //-------- actionSwitch ---------//
    goRef_.actionSwitch.bind_func( std::bind( &Leaf_DForest::OnActionSwitch, _1, _2 ) );
    goRef_.actionSwitch.signUp( ActionSwitchType::Move_Idle );
            //- 当前 leaf_DForest 只有一种动画，就是永久待机...

    //================ go self vals =================//
           
    //-- 务必在 mesh:"root" 之后 ---
    goRef_.goPos.init_currentDPos();
    //...

    //--- MUST ---
    goRef_.init_check();
}

/* ===========================================================
 *                       bind
 * -----------------------------------------------------------
 * -- 在 “工厂”模式中，将本具象go实例，与 一个已经存在的 go实例 绑定。
 * -- 这个 go实例 的类型，应该和 本类一致。
 */
void Leaf_DForest::bind( GameObj &goRef_ ){
}


/* ===========================================================
 *                       rebind
 * -----------------------------------------------------------
 * -- 从硬盘读取到 go实例数据后，重bind callback
 * -- 会被 脚本层的一个 巨型分配函数 调用
 */
void Leaf_DForest::rebind( GameObj &goRef_ ){
}

/* ===========================================================
 *                      OnRenderUpdate
 * -----------------------------------------------------------
 */
void Leaf_DForest::OnRenderUpdate( GameObj &goRef_ ){
    //=====================================//
    //            ptr rebind
    //-------------------------------------//
    Leaf_DForest_PvtBinary  *pvtBp = Leaf_DForest::rebind_ptr(goRef_);

    //=====================================//
    //               AI
    //-------------------------------------//
    //...

    //=====================================//
    //         更新 位移系统
    //-------------------------------------//
    //goRef_.move.RenderUpdate();
            // 目前来看，永远也不会 移动...

    //=====================================//
    //  将 确认要渲染的 goMeshs，添加到 renderPool         
    //-------------------------------------//
    goRef_.render_all_goMesh();
}


/* ===========================================================
 *                        OnLogicUpdate
 * -----------------------------------------------------------
 */
void Leaf_DForest::OnLogicUpdate( GameObj &goRef_ ){
    //=====================================//
    //            ptr rebind
    //-------------------------------------//
    Leaf_DForest_PvtBinary  *pvtBp = Leaf_DForest::rebind_ptr(goRef_);
    //=====================================//

    // 什么也没做...
}



/* ===========================================================
 *               OnActionSwitch
 * -----------------------------------------------------------
 * -- 此处用到的 animFrameIdxHdle实例，是每次用到时，临时 生产／改写 的
 * -- 会被 动作状态机 取代...
 */
void Leaf_DForest::OnActionSwitch( GameObj &goRef_, ActionSwitchType type_ ){

    //=====================================//
    //            ptr rebind
    //-------------------------------------//
    Leaf_DForest_PvtBinary  *pvtBp = Leaf_DForest::rebind_ptr(goRef_);
    //=====================================//

    //-- 获得所有 goMesh 的访问权 --
    GameObjMesh &rootGoMeshRef = goRef_.get_goMeshRef("root");

    //-- 处理不同的 actionSwitch 分支 --
    switch( type_ ){
        case ActionSwitchType::Move_Idle:
            //rootGoMeshRef.bind_animFrameSet( "norman" );
            //rootGoMeshRef.getnc_animFrameIdxHandle().bind_idle( pvtBp->leaf_DForestId );

            rootGoMeshRef.bind_animAction( "leaf_DForest", 
                                        tprGeneral::nameString_combine( "", pvtBp->leaf_DForestId, "_idle" ) );

            break;



        default:
            break;
            //-- 并不报错，什么也不做...

    }


}


}//------------- namespace gameObjs: end ----------------

