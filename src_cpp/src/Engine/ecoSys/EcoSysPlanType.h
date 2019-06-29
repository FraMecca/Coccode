/*
 * ====================== EcoSysPlanType.h =======================
 *                          -- tpr --
 *                                        CREATE -- 2019.02.22
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 *    ecosystem plan type
 * ----------------------------
 */
#ifndef TPR_ECOSYS_PLAN_TYPE_H_
#define TPR_ECOSYS_PLAN_TYPE_H_

//------------------- C --------------------//
#include <cstddef> //- size_t

//------------------- Libs --------------------//
#include "tprDataType.h" 


using ecoSysPlanId_t = u32_t;


//- 每一个type，都存在数个变种
enum class EcoSysPlanType : u32_t{

    BegIdx = 0, //- 通过此值来计算 第一个 typeIdx 是多少。
    
    //-- 确保所有 type 连续存放 --
    Forest,
    DarkForest,
    Plain,  
    Swamp,
    Desert,

    //----
    EndIdx //- 通过此值来计算 最后一个 typeIdx 是多少。
};


inline const size_t EcoSysPlanType_MinIdx { static_cast<size_t>(EcoSysPlanType::BegIdx) + 1 }; //- 最小序号
inline const size_t EcoSysPlanType_MaxIdx { static_cast<size_t>(EcoSysPlanType::EndIdx) - 1 }; //- 最大序号
inline const size_t EcoSysPlanType_Num  { EcoSysPlanType_MaxIdx - EcoSysPlanType_MinIdx + 1 }; //- type 个数

//-- 用来遍历 某些复合容器 --
inline size_t ecoSysPlanType_2_idx( EcoSysPlanType type_ ){
    return (static_cast<size_t>(type_) - EcoSysPlanType_MinIdx);
}


#endif 
