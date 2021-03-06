/***********************************************
 * File: UIElement.h
 *
 * Author: LYG
 * Date: ʮ���� 2018
 *
 * Purpose:
 *
 * 
 **********************************************/
#pragma once
#include "Math/Matrix4.h"

enum UIElementType
{
	ElementBackGroundSheet,
	ElementUIText,
	ElementButtonBG,
	ElementButtonTitle,
	ElementButtonText,
	ElementTextBeenCover,

};

class Mesh;
class UIElement
{
public:
	UIElementType GetElementType() const;
	void SetVisible(bool Visible);
	bool GetVisible() const;

	virtual void OnLButtonDown(int x, int y, unsigned int wParam);
	virtual void OnLButtonUp(int x, int y, unsigned int wParam);
	virtual void OnRButtonDown(int x, int y, unsigned int wParam);
	virtual void OnRButtonUp(int x, int y, unsigned int wParam);
	virtual void OnMouseMove(int x, int y, unsigned int wParam);
	virtual void OnLButtonDbclk(int x, int y, unsigned int wParam);
	virtual void OnRButtonDbclk(int x, int y, unsigned int wParam);
protected:
	UIElement();
	virtual ~UIElement();

	void Render(Matrix4 WorldTransform);

	Mesh* mMesh;
	UIElementType mElementType;
	Vector3 mMax;
	Vector3 mMin;
	bool mVisible;
};
