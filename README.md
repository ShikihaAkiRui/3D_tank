# 3D_tank
## 作成したプログラム説明
### 制作期間
　5か月　（2023年4月~9月)
### 作成人数
　個人
### 作成ツール
　Visual Studio 2019
### 使用言語 
　C++
### 使用ライブラリ
- DXライブラリ
- aquaライブラリ（校内製ライブラリ）
## 作成意図
　今まで 2D のゲームしか作っていなかったため、3D のプログラムの勉強し、より高度な知識を学びたいと考え作成しました。
初めての 3D だったのでカメラや当たり判定などの基礎が学びやすい簡単なゲームを目指し作成しました。
 ## 工夫した点
　学校内製の aqua ライブラリには 3D に関する処理がないためライブラリの処理の追加から行いました。
2D 同様にプログラムを書けるように、似た仕様にしながらも 3D ならではの違う処理や考え方を意識しながら作成しました。
次回以降の制作でも利用できるように、繰り返し呼ばれている処理を減らすなど汎用性があるよう心がけました。  
ゲーム部分のプログラムではキャラクターや弾の移動や回転の処理に力を入れました。
3Dになり軸が増え思っているように動かすことが難しかったですが、内積や外積、法線など今まで使ってこなかった知識を取り入れたり、式を解きなおしたり試行錯誤して解決しました。

## プログラム作成箇所
#### aquaライブラリ追加箇所
- aqua
  - src
    - graphics
      - collision
        - collision.h
        - collision.cpp
      - effect3D
        - effect3D.h
        - effect3D.cpp
      - model
        - model_manager
          - model_manager.h
          - model_manager.cpp
        - model_resource
          - model_resource.h
          - model_resource.cpp
        - model.h
        - model.cpp
    - mathematics
      - matrix
        - matrix.h
        - matrix.cpp
      - vector
        - vector3
          - vector3.h
          - vector3.cpp
     - utility
       - camera
         - camera.h
         -  camera.cpp
       - light
         - light.h
         - light.cpp
                           
