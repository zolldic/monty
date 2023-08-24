/**
  * _free_object - free object.
  * @object: object to free.
  */
void _free_object(obj_t *object)
{
	int i;
	/*
	   * to be free`d
	   * str, str_tokenized, ref_to_stack.
	   *
	*/
	if (object->str)
		free(object->str);
	i = 0;
	if (object->str_tokenized)
	{
		while (object->str_tokenized[i])
			free(object->str_tokenized[i++]);
		free(object->str_tokenized);
	}
	if (object->ref_to_stack)
		_free_stack(object->ref_to_stack);
	free(object);
}
