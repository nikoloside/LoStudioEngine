#pragma once

#define GLM_ENABLE_EXPERIMENTAL

#include "glm/glm.hpp"

/*
	描画用API群。
	GameMain内で使われることを想定している。
*/
namespace RenderAPI
{
    // スクリーンの幅を取得する
    int GetScreenWidth();
    // スクリーンの高さを取得する
    int GetScreenHeight();
    // スクリーンを指定色で塗りつぶす
	void ClearScreen(glm::vec3 const & color);

    // 描画色を設定する
    void SetColor(glm::vec3 const & color);
    // 画面上の座標を指定して、点を描画する。
    void DrawPoint(glm::vec2 const & point1, float depth);
    // 画面上の座標を指定して、円を描画する。
    void DrawCircle(glm::vec2 const & point1, float scale, float depth);
    // 画面上の2座標を指定して、線分を描画する。
    void DrawLine(glm::vec2 const & point1, glm::vec2 const & point2, glm::vec2 depth);
	// 画面上の3座標を指定して、三角形を描画する。
    void DrawTriangle(glm::vec2 const & point1, glm::vec2 const & point2, glm::vec2 const & point3, glm::vec3 depth);
    void ResetzBuffer();
}
