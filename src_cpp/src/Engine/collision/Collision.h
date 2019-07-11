/*
 * ========================= Collision.h ==========================
 *                          -- tpr --
 *                                        CREATE -- 2019.01.08
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 */
#ifndef TPR_COLLISION_H
#define TPR_COLLISION_H

//-------------------- CPP --------------------//
#include <string>

//-------------------- Engine --------------------//
#include "NineBox.h"

//--- need ---//
class GameObj;


//-- 和 Mesh 一样，也是一个 “整合类”
//
class Collision{
public:
    Collision( GameObj &goRef_ ):
        goRef(goRef_)
        {}

    bool detect_collision( const NineBoxIdx &nbIdx_ ); //-- 碰撞检测主流程 
                    //-- 临时的，局限性很大...

    inline void set_isDoPass( bool val_ ){
        this->isDoPass = val_;
    }
    inline void set_isBePass( bool val_ ){
        this->isBePass = val_;
    }

    inline bool get_isDoPass() const {
        return this->isDoPass;
    }
    inline bool get_isBePass() const {
        return this->isBePass;
    }

private:
    bool isPass_Check( bool isBePass_ );

    //======== vals ========//
    GameObj    &goRef;

    //======== flags ========//
    //  下方这组 可能存在 逻辑漏洞，但先这么用着... 
    bool  isDoPass  {false};//- 当自己为 主动go 时，是否穿过 被动go；
                            //  如果本go 是 “火球”／“箭”。可将此值设置为 true
                            //  此时，本go 将无视 被动go 的状态，移动穿过一切 被动go
    bool  isBePass  {false};//- 当自己为 被动go 时，是否允许 主动go 穿过自己；
                            //  如果本go 是 “草”／“腐蚀液”，可将此值 设置为 true
                            //  此时，本go 将无法阻止任何 go 从自己身上 穿过
};


#endif 

