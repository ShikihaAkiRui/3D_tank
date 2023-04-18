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
                @brief  モデルの解放
            */
            void    Unload(void);

            /*
                @brief  モデルの横幅取得

                @return モデルの横幅
            */
            int    GetWidth(void) {return m_Width; }
           
            /*
                @brief  モデルの縦幅取得

                @return モデルの縦幅
            */
            int     GetHeight(void) { return m_Height; }

            /*
                @brief  モデルの奥行取得

                @return モデルの奥行
            */
            int     GetDepth(void) { return m_Depth; }

        private:
            /*
                brief   クラスをフレンド登録
            */
            friend class CModel;
            friend class CModelManager;

            /*
                @brief  モデルの生成

                @param[in]  width       横幅
                @param[in]  height      縦幅
                @param[in]  depth       奥行
                @param[in]  alpha_channel   アルファチャンネル
            */
            void    Create(int width, int height, int depth, bool alpha_channel);

            /*
                @brief  モデルの解放
            */
            void    Delete(void);

            //!透過色（マゼンタ0xff00ff)
            static const unsigned int m_transparent_color;
            //!モデルの幅
            int m_Width;
            //!モデルの高さ
            int m_Height;
            //!モデルの奥行
            int m_Depth;
        };
    }
}
