
/**********************************************************************
*Project           : ColdEngine
*
*Author : Lucas García
*
*
*Purpose : 3D Engine compiled as a static library (.lib) that can generate an .exe
*
**********************************************************************/

#include "MeshRenderer.h"
#include <Model.hpp>
#include <Model_Obj.hpp>
#include <Material.hpp>
namespace coldEngine
{
	void MeshRenderer::Translate(float x, float y, float z)
	{
		model->translate(glt::Vector3(x, y, z));
	}
	void MeshRenderer::Rotate(float x, float y, float z)
	{
		model->rotate_around_x(x);
		model->rotate_around_y(y);
		model->rotate_around_z(z);
	}

	void MeshRenderer::Scale(float x, float y, float z)
	{
		model->scale(x, y, z);
	}

	MeshRenderer::MeshRenderer( Node* _model, Entity& _entity)
	{
		SetEntity(&_entity);
		model = _model;
	}
	void MeshRenderer::Update(float x, float y, float z, float xRot, float yRot, float zRot,float xSca, float ySca, float zSca)
	{	
		 glt::Node::Transformation transformation = model->get_transformation();
		 // Aplicar una traslación
		 transformation = glt::scale(transformation, xSca, ySca, zSca);

		 // Applies a rotation
		 transformation = glt::rotate_around_x(transformation, xRot);

		 // Applies a rotation		 
		 transformation = glt::rotate_around_y(transformation, yRot);

		 // Applies a rotation
		 transformation = glt::rotate_around_z(transformation, zRot);
		 transformation = glt::translate(transformation, glt::Vector3(x, y, z));
		 //model->reset_transformation();

		 // Applies a scale
		model->set_transformation(transformation);

	}
}


