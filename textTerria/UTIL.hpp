#pragma once
#pragma comment(lib, "MSIMG32.LIB")
#include <easyx.h>
#include "Transform.h"
inline bool check_point_in_rectangle(const Vector2& point, const Vector2& range1, const Vector2& range2) {
	if (point.x > (range1.x < range2.x ? range1.x : range2.x) && point.x < (range1.x > range2.x ? range1.x : range2.x) &&
		point.y >(range1.y < range2.y ? range1.y : range2.y) && point.y < (range1.y > range2.y ? range1.y : range2.y))
		return true;
	return false;
}
inline bool check_point_in_rectangle(const Vector2& point, const Transform& range) {
	return check_point_in_rectangle(point, range.get_position(), range.get_size() + range.get_position());
}

template<typename T>
inline void clearVec(std::vector<T*> vec)
{
	for (T* i : vec)
	{
		delete i;
	}
	vec.clear();
}

//透明通道混合绘图
void putImage(int dstX, int dstY, IMAGE* pSrcImg, DWORD dwRop = SRCCOPY)
{
	DWORD* pSrcImgBuffer = GetImageBuffer(pSrcImg);
	//获取目标图像缓冲区指针
	DWORD* pDstImgBuffer = GetImageBuffer();
	int i32SrcWidth = pSrcImg->getwidth();
	int i32SrcHight = pSrcImg->getheight();
	int i32DstWidth = GetWorkingImage()->getwidth();
	int i32DstHeight = GetWorkingImage()->getheight();
	for (int y = 0; y < i32SrcHight; y++)
	{
		for (int x = 0; x < i32SrcWidth; x++)
		{
			DWORD dwCurSrcColor = pSrcImgBuffer[x + y * i32SrcWidth];
			BYTE byteSrcAlpha = dwCurSrcColor >> 24;
			BYTE byteSrcRed = dwCurSrcColor >> 16;
			BYTE byteSrcGreen = dwCurSrcColor >> 8;
			BYTE byteSrcBlue = dwCurSrcColor;
			if (dstX + x > i32DstWidth || dstY + y > i32DstHeight)
			{
				continue;
			}
			int i32DstIndex = (dstX + x) + (dstY + y) * i32DstWidth;
			DWORD dwCurDstColor = pDstImgBuffer[i32DstIndex];
			BYTE byteDstRed = dwCurDstColor >> 16;
			BYTE byteDstGreen = dwCurDstColor >> 8;
			BYTE byteDstBlue = dwCurDstColor;

			//根据alpha通道实现颜色混合
			byteDstRed = (byteSrcRed * byteSrcAlpha + byteDstRed * (255 - byteSrcAlpha)) / 255;
			byteDstGreen = (byteSrcGreen * byteSrcAlpha + byteDstGreen * (255 - byteSrcAlpha)) / 255;
			byteDstBlue = (byteSrcBlue * byteSrcAlpha + byteDstBlue * (255 - byteSrcAlpha)) / 255;

			pDstImgBuffer[i32DstIndex] = RGB(byteDstRed, byteDstGreen, byteDstBlue);
		}
	}
}
//使用windowsAPI缩放 -- deepseek
void putImage(int dstX, int dstY, int dstWidth, int dstHeight, IMAGE* pSrcImg, int srcX, int srcY, int srcWidth, int srcHeight)
{
	HDC dstDC = GetImageHDC(NULL); // 目标DC（通常是屏幕）
	HDC srcDC = GetImageHDC(pSrcImg); // 源图像DC

	BLENDFUNCTION bf = { AC_SRC_OVER, 0, 255, AC_SRC_ALPHA }; // 混合函数结构体

	// 调用 AlphaBlend。注意：这里的缩放由 Windows 内部处理，质量通常优于手动插值。
	AlphaBlend(
		dstDC, dstX, dstY, dstWidth, dstHeight, // 目标位置和大小
		srcDC, srcX, srcY, srcWidth, srcHeight, // 源位置和大小
		bf
	);
}