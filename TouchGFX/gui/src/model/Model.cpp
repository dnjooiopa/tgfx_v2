#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>

Model::Model() : modelListener(0)
{
	gui_msg_q = xQueueGenericCreate(1, 1, 0);
}

void Model::tick()
{

}
