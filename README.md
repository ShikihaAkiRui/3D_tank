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

#### ゲームプログラム作成箇所
- game
  - src
    - game
      - game.cpp
      - game_object
        - bullet_manager
          - bullet_manager.h
          - bullet_manager.cpp
          - bullet
            - bullet.h
            - bullet.cpp
            - bullet_id.h
            - bullet_normal
              - bullet_normal.h
              - bullet_normal.cpp
            - bullet_parabola
              - bullet_parabola.h
              - bullet_parabola.cpp
        - control_camera
          - control_camera.h
          - control_camera.cpp
        - control_light
          - control_light.h
          - control_libht.cpp
        - effect_manager
          - effect_manager.h
          - effect_manager.cpp
          - effect
            - effect.h
            - effect.cpp
            - effect_id.h
            - explosion_effect
              - explosion_effect.h
              - explosion_effect.cpp
            - graund_hit_bullet_effect
              - graund_hit_bullet_effect.h
              - graund_hit_bullet_effect.cpp
            - hit_player_effect
              - hit_player_effect.h
              - hit_player_effect.cpp
            - not_hit_effect
              - not_hit_effect.h
              - not_hit_effect.cpp
        - enemy_appear
          - enemy_appear.h
          - enemy_appear.cpp
        - game_sound_manager
          - game_sound_manager.h
          - game_sound_manager.cpp
        - item_manager
          - item_manager.h
          - item_manager.cpp
          - item
            - item.h
            - item.cpp
        - scene_manager
          - scene_manager.h
          - scene_manager.cpp
          - scene
            - scene.h
            - scene.cpp
            - scene_id.h
            - title_scene
               - title_scene.h
               - title_scene.cpp
            - gamemain_scene
              - gamemain_scene.h
              - gamemain_scene.cpp
              - result_scene
                - result_scene.h
                - result_scene.cpp
       - stage
         - stage.h
         - stage.cpp
       - ui_manager
         - ui_manager.h
         - ui_manager.cpp
         - ui_component
           - ui_component.h
           - ui_component.cpp
           - ui_id.h
           - aim
             - aim.h
             - aim.cpp
           - click_message
             - click_message.h
             - click_message.cpp
           - end_message
             - end_message.h
             - end_message.cpp
           - life
             - life.h
             - life.cpp
           - radar
             - radar.h
             - radar.cpp
           - score
             - score.h
             - score.cpp
           - show_score
             - show_score.h
             - show_score.cpp
           - start_message
             - start_message.h
             - start_message.cpp
           - title_name
             - title_name.h
             - title_name.cpp
       - unit
         - unit.h
         - unit.cpp
       - unit_manager
         - unit_manager.h
         - unit_manager.cpp
         - unit_id.h
         - character
           - character.h
           - character.cpp
         - enemy
           - enemy.h
           - enemy.cpp
           - enemy_fly
             - enemy_fly.h
             - enemy_fly.cpp
           - enemy_normal
             - enemy_normal.h
             - enemy_normal.cpp
           - enemy_parabola
             - enemy_parabola.h
             - enemy_parabola.cpp
         - player
           - player.h
           - player.cpp
