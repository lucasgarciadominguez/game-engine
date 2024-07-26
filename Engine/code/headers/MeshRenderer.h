
/**
 * \author Lucas Garcia
 * \version 1.0
 * \date 2024-06-18
 */

 /**
  * \class MeshRenderer
  * \brief Component that manages the graphic aspect of every entity.
  *
  * Sets the transform attributes in the component via this class
  */


#pragma once

#include <string>
#include<declarations.h>
#include "Component.h" 

using namespace glt;
using namespace std;

namespace coldEngine
{
	class Scene;
	class Transformation;

	class MeshRenderer: public Component
	{

		Node* model;
	private:

		void Translate(float x, float y, float z);		

		void Rotate(float x, float y, float z);
		
		void Scale(float x, float y, float z);

	public:
		///
		/// Constructor
		///
		MeshRenderer(Node* _model ,Entity& _entity);
		void Update(float x, float y, float z, float xRot, float yRot, float zRot, float xSca, float ySca, float zSca);


	};
}

