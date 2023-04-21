/*!
    @file   model_resource.h
    @brief  モデルリソース
 */

#pragma once

#include"../../../resources/resources.h"

/*
    aqua名前空間
*/
namespace aqua
{
    /*
        aqua::core名前空間
    */
    namespace core
    {
        /*
            @class  CModelResource

            @brief  モデルリソースクラス
        */
        class CModelResource : public IResourceObject
        {
            /*
                @brief  コンストラクタ
            */
            CModelResource(void);

            /*
                @brief  デストラクタ
            */
            ~CModelResource(void) = default;

            /*
                @brief  モデルの読み込み

                @param[in]  file_name    ファイル名
            */
            void   Load(const std::string& file_name);

            /*
                @brief  モデルがある場合の読み込み

                @param[in]  model  モデルリソースクラス
            */
            void    Duplicate(const CModelResource* model);

            /*
                @brief  モデルの解放
            */
            void    Unload(void);         


        private:
            /*
                brief   クラスをフレンド登録
            */
            friend class CModel;
            friend class CModelManager;


        };
    }
}
