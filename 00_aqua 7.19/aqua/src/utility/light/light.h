#pragma once

#include<DxLib.h>
#include"../../mathematics/vector/vector.h"

/*
	aqua¼OóÔ
*/
namespace aqua
{
	/*
		@class CLight

		@brief CgNX
	*/

	class CLight
	{
	public:
		//!ûü
		CVector3 m_Direction;
		//!Êu
		CVector3 m_Position;
		//!Lø£
		float m_Range;
		//!£¸
		float m_Attenuation;
		//!£¸(äá)
		float m_AttenuationProportion;
		//!£¸(ñæ)
		float m_AttenuationSquaring;

		/*
			@brief	RXgN^
		*/
		CLight(void);

		/*
			@brief	fXgN^
		*/
		~CLight(void) = default;

		void	Initialize(void);

		/*
			@brief	XV
		*/
		void	Update(void);

		/*
			@brief	WCgÌ^CvðfBNViCgÉ·é

			@param[in]	direction	ûü
		*/
		void ChangeTypeDir(const aqua::CVector3& direction);
		
		/*
			@brief	WCgÌ^Cvð|CgCgÉ·é

			@param[in]	position	Êu
			@param[in]	range	Lø£
			@param[in]	attenuation	£¸
			@param[in]	attenuation_proportion	£¸(äá)
			@param[in]	attenuation_squaring	£¸(ñæ)
		*/
		void	ChangeTypePoint(const aqua::CVector3& position, float range, float attenuation, float attenuation_proportion, float attenuation_squaring);

	private:

		//!ûüÌúl
		static const CVector3 m_default_direction;
		//!ÊuÌúl
		static const CVector3 m_default_position;
		//!Lø£Ìúl
		static const float m_default_range;
		//!£¸Ìúl
		static const float m_default_attenuation;
		//!£¸(äá)Ìúl
		static const float m_default_attenuation_proportion;
		//!£¸(ñæ)Ìúl
		static const float m_default_attenuation_squaring;
	};

}