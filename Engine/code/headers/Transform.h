
/**
 * \author Lucas Garcia
 * \version 1.0
 * \date 2024-06-18
 */

 /**
  * \class Transform
  * \brief Component for showing the coordinates of the entity, same as Unity or Unreal does
  */


#include "Component.h" 
#include "Position.h"
#include "Rotation.h"
#include "Scale.h"
#pragma once
namespace coldEngine
{
	class Transform : public Component
	{
		Position* position;
		Rotation* rotation;
		Scale* scale;



	public:
		Transform()
		{
			position = new Position();
			rotation = new Rotation();
			scale = new Scale();
		}
		~Transform()
		{
			delete position;
			delete rotation;
			delete scale;
		}

        void SetPosition(float x, float y, float z)
        {
            position->SetPosition(x, y, z);
        }
        void SetRotation(float x, float y, float z)
        {
            rotation->SetRotation(x, y, z);
        }
        void SetScale(float x, float y, float z)
        {
            scale->SetScale(x, y, z);
        }

        void GetPosition(float& x, float& y, float& z)
        {
            position->GetPosition(x, y, z);
        }
        void GetRotation(float& x, float& y, float& z)
        {
            rotation->GetRotation(x, y, z);
        }
		void GetScale(float& x, float& y, float& z)
		{
			scale->GetScale(x, y, z);
		}

		void Translate(float x, float y, float z)
		{
			position->Translate(x,y,z);
		}

		void GetLastTransformation(float& x, float& y, float& z)
		{
			position->GetLastTransformation(x,y,z);
		}
		void GetLastTransformationScale(float& x, float& y, float& z)
		{
			//scale->GetLastTransformation(x, y, z);
		}
	};
}


