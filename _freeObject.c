#include "monty.h"
/**
  * _free_object - free object.
  * @object: object to free.
  */
void _free_object(obj_t *object)
{
	if (object)
	{
		if (object->str)
			free(object->str);
		if (object->ref_to_stack)
		{
			_free_stack(object->ref_to_stack);
			free(object->ref_to_stack);
		}
		free(object);
	}
}
