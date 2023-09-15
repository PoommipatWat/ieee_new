// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from xicro_interfaces:action/Toggle.idl
// generated code does not contain a copyright notice
#include "xicro_interfaces/action/detail/toggle__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


bool
xicro_interfaces__action__Toggle_Goal__init(xicro_interfaces__action__Toggle_Goal * msg)
{
  if (!msg) {
    return false;
  }
  // a
  return true;
}

void
xicro_interfaces__action__Toggle_Goal__fini(xicro_interfaces__action__Toggle_Goal * msg)
{
  if (!msg) {
    return;
  }
  // a
}

bool
xicro_interfaces__action__Toggle_Goal__are_equal(const xicro_interfaces__action__Toggle_Goal * lhs, const xicro_interfaces__action__Toggle_Goal * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // a
  if (lhs->a != rhs->a) {
    return false;
  }
  return true;
}

bool
xicro_interfaces__action__Toggle_Goal__copy(
  const xicro_interfaces__action__Toggle_Goal * input,
  xicro_interfaces__action__Toggle_Goal * output)
{
  if (!input || !output) {
    return false;
  }
  // a
  output->a = input->a;
  return true;
}

xicro_interfaces__action__Toggle_Goal *
xicro_interfaces__action__Toggle_Goal__create()
{
  xicro_interfaces__action__Toggle_Goal * msg = (xicro_interfaces__action__Toggle_Goal *)malloc(sizeof(xicro_interfaces__action__Toggle_Goal));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(xicro_interfaces__action__Toggle_Goal));
  bool success = xicro_interfaces__action__Toggle_Goal__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
xicro_interfaces__action__Toggle_Goal__destroy(xicro_interfaces__action__Toggle_Goal * msg)
{
  if (msg) {
    xicro_interfaces__action__Toggle_Goal__fini(msg);
  }
  free(msg);
}


bool
xicro_interfaces__action__Toggle_Goal__Sequence__init(xicro_interfaces__action__Toggle_Goal__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  xicro_interfaces__action__Toggle_Goal * data = NULL;
  if (size) {
    data = (xicro_interfaces__action__Toggle_Goal *)calloc(size, sizeof(xicro_interfaces__action__Toggle_Goal));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = xicro_interfaces__action__Toggle_Goal__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        xicro_interfaces__action__Toggle_Goal__fini(&data[i - 1]);
      }
      free(data);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
xicro_interfaces__action__Toggle_Goal__Sequence__fini(xicro_interfaces__action__Toggle_Goal__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      xicro_interfaces__action__Toggle_Goal__fini(&array->data[i]);
    }
    free(array->data);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

xicro_interfaces__action__Toggle_Goal__Sequence *
xicro_interfaces__action__Toggle_Goal__Sequence__create(size_t size)
{
  xicro_interfaces__action__Toggle_Goal__Sequence * array = (xicro_interfaces__action__Toggle_Goal__Sequence *)malloc(sizeof(xicro_interfaces__action__Toggle_Goal__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = xicro_interfaces__action__Toggle_Goal__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
xicro_interfaces__action__Toggle_Goal__Sequence__destroy(xicro_interfaces__action__Toggle_Goal__Sequence * array)
{
  if (array) {
    xicro_interfaces__action__Toggle_Goal__Sequence__fini(array);
  }
  free(array);
}

bool
xicro_interfaces__action__Toggle_Goal__Sequence__are_equal(const xicro_interfaces__action__Toggle_Goal__Sequence * lhs, const xicro_interfaces__action__Toggle_Goal__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!xicro_interfaces__action__Toggle_Goal__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
xicro_interfaces__action__Toggle_Goal__Sequence__copy(
  const xicro_interfaces__action__Toggle_Goal__Sequence * input,
  xicro_interfaces__action__Toggle_Goal__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(xicro_interfaces__action__Toggle_Goal);
    xicro_interfaces__action__Toggle_Goal * data =
      (xicro_interfaces__action__Toggle_Goal *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!xicro_interfaces__action__Toggle_Goal__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          xicro_interfaces__action__Toggle_Goal__fini(&data[i]);
        }
        free(data);
        return false;
      }
    }
    output->data = data;
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!xicro_interfaces__action__Toggle_Goal__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


bool
xicro_interfaces__action__Toggle_Result__init(xicro_interfaces__action__Toggle_Result * msg)
{
  if (!msg) {
    return false;
  }
  // sum
  return true;
}

void
xicro_interfaces__action__Toggle_Result__fini(xicro_interfaces__action__Toggle_Result * msg)
{
  if (!msg) {
    return;
  }
  // sum
}

bool
xicro_interfaces__action__Toggle_Result__are_equal(const xicro_interfaces__action__Toggle_Result * lhs, const xicro_interfaces__action__Toggle_Result * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // sum
  if (lhs->sum != rhs->sum) {
    return false;
  }
  return true;
}

bool
xicro_interfaces__action__Toggle_Result__copy(
  const xicro_interfaces__action__Toggle_Result * input,
  xicro_interfaces__action__Toggle_Result * output)
{
  if (!input || !output) {
    return false;
  }
  // sum
  output->sum = input->sum;
  return true;
}

xicro_interfaces__action__Toggle_Result *
xicro_interfaces__action__Toggle_Result__create()
{
  xicro_interfaces__action__Toggle_Result * msg = (xicro_interfaces__action__Toggle_Result *)malloc(sizeof(xicro_interfaces__action__Toggle_Result));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(xicro_interfaces__action__Toggle_Result));
  bool success = xicro_interfaces__action__Toggle_Result__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
xicro_interfaces__action__Toggle_Result__destroy(xicro_interfaces__action__Toggle_Result * msg)
{
  if (msg) {
    xicro_interfaces__action__Toggle_Result__fini(msg);
  }
  free(msg);
}


bool
xicro_interfaces__action__Toggle_Result__Sequence__init(xicro_interfaces__action__Toggle_Result__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  xicro_interfaces__action__Toggle_Result * data = NULL;
  if (size) {
    data = (xicro_interfaces__action__Toggle_Result *)calloc(size, sizeof(xicro_interfaces__action__Toggle_Result));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = xicro_interfaces__action__Toggle_Result__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        xicro_interfaces__action__Toggle_Result__fini(&data[i - 1]);
      }
      free(data);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
xicro_interfaces__action__Toggle_Result__Sequence__fini(xicro_interfaces__action__Toggle_Result__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      xicro_interfaces__action__Toggle_Result__fini(&array->data[i]);
    }
    free(array->data);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

xicro_interfaces__action__Toggle_Result__Sequence *
xicro_interfaces__action__Toggle_Result__Sequence__create(size_t size)
{
  xicro_interfaces__action__Toggle_Result__Sequence * array = (xicro_interfaces__action__Toggle_Result__Sequence *)malloc(sizeof(xicro_interfaces__action__Toggle_Result__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = xicro_interfaces__action__Toggle_Result__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
xicro_interfaces__action__Toggle_Result__Sequence__destroy(xicro_interfaces__action__Toggle_Result__Sequence * array)
{
  if (array) {
    xicro_interfaces__action__Toggle_Result__Sequence__fini(array);
  }
  free(array);
}

bool
xicro_interfaces__action__Toggle_Result__Sequence__are_equal(const xicro_interfaces__action__Toggle_Result__Sequence * lhs, const xicro_interfaces__action__Toggle_Result__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!xicro_interfaces__action__Toggle_Result__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
xicro_interfaces__action__Toggle_Result__Sequence__copy(
  const xicro_interfaces__action__Toggle_Result__Sequence * input,
  xicro_interfaces__action__Toggle_Result__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(xicro_interfaces__action__Toggle_Result);
    xicro_interfaces__action__Toggle_Result * data =
      (xicro_interfaces__action__Toggle_Result *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!xicro_interfaces__action__Toggle_Result__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          xicro_interfaces__action__Toggle_Result__fini(&data[i]);
        }
        free(data);
        return false;
      }
    }
    output->data = data;
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!xicro_interfaces__action__Toggle_Result__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


bool
xicro_interfaces__action__Toggle_Feedback__init(xicro_interfaces__action__Toggle_Feedback * msg)
{
  if (!msg) {
    return false;
  }
  // flag
  return true;
}

void
xicro_interfaces__action__Toggle_Feedback__fini(xicro_interfaces__action__Toggle_Feedback * msg)
{
  if (!msg) {
    return;
  }
  // flag
}

bool
xicro_interfaces__action__Toggle_Feedback__are_equal(const xicro_interfaces__action__Toggle_Feedback * lhs, const xicro_interfaces__action__Toggle_Feedback * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // flag
  if (lhs->flag != rhs->flag) {
    return false;
  }
  return true;
}

bool
xicro_interfaces__action__Toggle_Feedback__copy(
  const xicro_interfaces__action__Toggle_Feedback * input,
  xicro_interfaces__action__Toggle_Feedback * output)
{
  if (!input || !output) {
    return false;
  }
  // flag
  output->flag = input->flag;
  return true;
}

xicro_interfaces__action__Toggle_Feedback *
xicro_interfaces__action__Toggle_Feedback__create()
{
  xicro_interfaces__action__Toggle_Feedback * msg = (xicro_interfaces__action__Toggle_Feedback *)malloc(sizeof(xicro_interfaces__action__Toggle_Feedback));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(xicro_interfaces__action__Toggle_Feedback));
  bool success = xicro_interfaces__action__Toggle_Feedback__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
xicro_interfaces__action__Toggle_Feedback__destroy(xicro_interfaces__action__Toggle_Feedback * msg)
{
  if (msg) {
    xicro_interfaces__action__Toggle_Feedback__fini(msg);
  }
  free(msg);
}


bool
xicro_interfaces__action__Toggle_Feedback__Sequence__init(xicro_interfaces__action__Toggle_Feedback__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  xicro_interfaces__action__Toggle_Feedback * data = NULL;
  if (size) {
    data = (xicro_interfaces__action__Toggle_Feedback *)calloc(size, sizeof(xicro_interfaces__action__Toggle_Feedback));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = xicro_interfaces__action__Toggle_Feedback__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        xicro_interfaces__action__Toggle_Feedback__fini(&data[i - 1]);
      }
      free(data);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
xicro_interfaces__action__Toggle_Feedback__Sequence__fini(xicro_interfaces__action__Toggle_Feedback__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      xicro_interfaces__action__Toggle_Feedback__fini(&array->data[i]);
    }
    free(array->data);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

xicro_interfaces__action__Toggle_Feedback__Sequence *
xicro_interfaces__action__Toggle_Feedback__Sequence__create(size_t size)
{
  xicro_interfaces__action__Toggle_Feedback__Sequence * array = (xicro_interfaces__action__Toggle_Feedback__Sequence *)malloc(sizeof(xicro_interfaces__action__Toggle_Feedback__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = xicro_interfaces__action__Toggle_Feedback__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
xicro_interfaces__action__Toggle_Feedback__Sequence__destroy(xicro_interfaces__action__Toggle_Feedback__Sequence * array)
{
  if (array) {
    xicro_interfaces__action__Toggle_Feedback__Sequence__fini(array);
  }
  free(array);
}

bool
xicro_interfaces__action__Toggle_Feedback__Sequence__are_equal(const xicro_interfaces__action__Toggle_Feedback__Sequence * lhs, const xicro_interfaces__action__Toggle_Feedback__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!xicro_interfaces__action__Toggle_Feedback__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
xicro_interfaces__action__Toggle_Feedback__Sequence__copy(
  const xicro_interfaces__action__Toggle_Feedback__Sequence * input,
  xicro_interfaces__action__Toggle_Feedback__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(xicro_interfaces__action__Toggle_Feedback);
    xicro_interfaces__action__Toggle_Feedback * data =
      (xicro_interfaces__action__Toggle_Feedback *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!xicro_interfaces__action__Toggle_Feedback__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          xicro_interfaces__action__Toggle_Feedback__fini(&data[i]);
        }
        free(data);
        return false;
      }
    }
    output->data = data;
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!xicro_interfaces__action__Toggle_Feedback__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `goal_id`
#include "unique_identifier_msgs/msg/detail/uuid__functions.h"
// Member `goal`
// already included above
// #include "xicro_interfaces/action/detail/toggle__functions.h"

bool
xicro_interfaces__action__Toggle_SendGoal_Request__init(xicro_interfaces__action__Toggle_SendGoal_Request * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    xicro_interfaces__action__Toggle_SendGoal_Request__fini(msg);
    return false;
  }
  // goal
  if (!xicro_interfaces__action__Toggle_Goal__init(&msg->goal)) {
    xicro_interfaces__action__Toggle_SendGoal_Request__fini(msg);
    return false;
  }
  return true;
}

void
xicro_interfaces__action__Toggle_SendGoal_Request__fini(xicro_interfaces__action__Toggle_SendGoal_Request * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
  // goal
  xicro_interfaces__action__Toggle_Goal__fini(&msg->goal);
}

bool
xicro_interfaces__action__Toggle_SendGoal_Request__are_equal(const xicro_interfaces__action__Toggle_SendGoal_Request * lhs, const xicro_interfaces__action__Toggle_SendGoal_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  // goal
  if (!xicro_interfaces__action__Toggle_Goal__are_equal(
      &(lhs->goal), &(rhs->goal)))
  {
    return false;
  }
  return true;
}

bool
xicro_interfaces__action__Toggle_SendGoal_Request__copy(
  const xicro_interfaces__action__Toggle_SendGoal_Request * input,
  xicro_interfaces__action__Toggle_SendGoal_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  // goal
  if (!xicro_interfaces__action__Toggle_Goal__copy(
      &(input->goal), &(output->goal)))
  {
    return false;
  }
  return true;
}

xicro_interfaces__action__Toggle_SendGoal_Request *
xicro_interfaces__action__Toggle_SendGoal_Request__create()
{
  xicro_interfaces__action__Toggle_SendGoal_Request * msg = (xicro_interfaces__action__Toggle_SendGoal_Request *)malloc(sizeof(xicro_interfaces__action__Toggle_SendGoal_Request));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(xicro_interfaces__action__Toggle_SendGoal_Request));
  bool success = xicro_interfaces__action__Toggle_SendGoal_Request__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
xicro_interfaces__action__Toggle_SendGoal_Request__destroy(xicro_interfaces__action__Toggle_SendGoal_Request * msg)
{
  if (msg) {
    xicro_interfaces__action__Toggle_SendGoal_Request__fini(msg);
  }
  free(msg);
}


bool
xicro_interfaces__action__Toggle_SendGoal_Request__Sequence__init(xicro_interfaces__action__Toggle_SendGoal_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  xicro_interfaces__action__Toggle_SendGoal_Request * data = NULL;
  if (size) {
    data = (xicro_interfaces__action__Toggle_SendGoal_Request *)calloc(size, sizeof(xicro_interfaces__action__Toggle_SendGoal_Request));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = xicro_interfaces__action__Toggle_SendGoal_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        xicro_interfaces__action__Toggle_SendGoal_Request__fini(&data[i - 1]);
      }
      free(data);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
xicro_interfaces__action__Toggle_SendGoal_Request__Sequence__fini(xicro_interfaces__action__Toggle_SendGoal_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      xicro_interfaces__action__Toggle_SendGoal_Request__fini(&array->data[i]);
    }
    free(array->data);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

xicro_interfaces__action__Toggle_SendGoal_Request__Sequence *
xicro_interfaces__action__Toggle_SendGoal_Request__Sequence__create(size_t size)
{
  xicro_interfaces__action__Toggle_SendGoal_Request__Sequence * array = (xicro_interfaces__action__Toggle_SendGoal_Request__Sequence *)malloc(sizeof(xicro_interfaces__action__Toggle_SendGoal_Request__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = xicro_interfaces__action__Toggle_SendGoal_Request__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
xicro_interfaces__action__Toggle_SendGoal_Request__Sequence__destroy(xicro_interfaces__action__Toggle_SendGoal_Request__Sequence * array)
{
  if (array) {
    xicro_interfaces__action__Toggle_SendGoal_Request__Sequence__fini(array);
  }
  free(array);
}

bool
xicro_interfaces__action__Toggle_SendGoal_Request__Sequence__are_equal(const xicro_interfaces__action__Toggle_SendGoal_Request__Sequence * lhs, const xicro_interfaces__action__Toggle_SendGoal_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!xicro_interfaces__action__Toggle_SendGoal_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
xicro_interfaces__action__Toggle_SendGoal_Request__Sequence__copy(
  const xicro_interfaces__action__Toggle_SendGoal_Request__Sequence * input,
  xicro_interfaces__action__Toggle_SendGoal_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(xicro_interfaces__action__Toggle_SendGoal_Request);
    xicro_interfaces__action__Toggle_SendGoal_Request * data =
      (xicro_interfaces__action__Toggle_SendGoal_Request *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!xicro_interfaces__action__Toggle_SendGoal_Request__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          xicro_interfaces__action__Toggle_SendGoal_Request__fini(&data[i]);
        }
        free(data);
        return false;
      }
    }
    output->data = data;
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!xicro_interfaces__action__Toggle_SendGoal_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `stamp`
#include "builtin_interfaces/msg/detail/time__functions.h"

bool
xicro_interfaces__action__Toggle_SendGoal_Response__init(xicro_interfaces__action__Toggle_SendGoal_Response * msg)
{
  if (!msg) {
    return false;
  }
  // accepted
  // stamp
  if (!builtin_interfaces__msg__Time__init(&msg->stamp)) {
    xicro_interfaces__action__Toggle_SendGoal_Response__fini(msg);
    return false;
  }
  return true;
}

void
xicro_interfaces__action__Toggle_SendGoal_Response__fini(xicro_interfaces__action__Toggle_SendGoal_Response * msg)
{
  if (!msg) {
    return;
  }
  // accepted
  // stamp
  builtin_interfaces__msg__Time__fini(&msg->stamp);
}

bool
xicro_interfaces__action__Toggle_SendGoal_Response__are_equal(const xicro_interfaces__action__Toggle_SendGoal_Response * lhs, const xicro_interfaces__action__Toggle_SendGoal_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // accepted
  if (lhs->accepted != rhs->accepted) {
    return false;
  }
  // stamp
  if (!builtin_interfaces__msg__Time__are_equal(
      &(lhs->stamp), &(rhs->stamp)))
  {
    return false;
  }
  return true;
}

bool
xicro_interfaces__action__Toggle_SendGoal_Response__copy(
  const xicro_interfaces__action__Toggle_SendGoal_Response * input,
  xicro_interfaces__action__Toggle_SendGoal_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // accepted
  output->accepted = input->accepted;
  // stamp
  if (!builtin_interfaces__msg__Time__copy(
      &(input->stamp), &(output->stamp)))
  {
    return false;
  }
  return true;
}

xicro_interfaces__action__Toggle_SendGoal_Response *
xicro_interfaces__action__Toggle_SendGoal_Response__create()
{
  xicro_interfaces__action__Toggle_SendGoal_Response * msg = (xicro_interfaces__action__Toggle_SendGoal_Response *)malloc(sizeof(xicro_interfaces__action__Toggle_SendGoal_Response));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(xicro_interfaces__action__Toggle_SendGoal_Response));
  bool success = xicro_interfaces__action__Toggle_SendGoal_Response__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
xicro_interfaces__action__Toggle_SendGoal_Response__destroy(xicro_interfaces__action__Toggle_SendGoal_Response * msg)
{
  if (msg) {
    xicro_interfaces__action__Toggle_SendGoal_Response__fini(msg);
  }
  free(msg);
}


bool
xicro_interfaces__action__Toggle_SendGoal_Response__Sequence__init(xicro_interfaces__action__Toggle_SendGoal_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  xicro_interfaces__action__Toggle_SendGoal_Response * data = NULL;
  if (size) {
    data = (xicro_interfaces__action__Toggle_SendGoal_Response *)calloc(size, sizeof(xicro_interfaces__action__Toggle_SendGoal_Response));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = xicro_interfaces__action__Toggle_SendGoal_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        xicro_interfaces__action__Toggle_SendGoal_Response__fini(&data[i - 1]);
      }
      free(data);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
xicro_interfaces__action__Toggle_SendGoal_Response__Sequence__fini(xicro_interfaces__action__Toggle_SendGoal_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      xicro_interfaces__action__Toggle_SendGoal_Response__fini(&array->data[i]);
    }
    free(array->data);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

xicro_interfaces__action__Toggle_SendGoal_Response__Sequence *
xicro_interfaces__action__Toggle_SendGoal_Response__Sequence__create(size_t size)
{
  xicro_interfaces__action__Toggle_SendGoal_Response__Sequence * array = (xicro_interfaces__action__Toggle_SendGoal_Response__Sequence *)malloc(sizeof(xicro_interfaces__action__Toggle_SendGoal_Response__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = xicro_interfaces__action__Toggle_SendGoal_Response__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
xicro_interfaces__action__Toggle_SendGoal_Response__Sequence__destroy(xicro_interfaces__action__Toggle_SendGoal_Response__Sequence * array)
{
  if (array) {
    xicro_interfaces__action__Toggle_SendGoal_Response__Sequence__fini(array);
  }
  free(array);
}

bool
xicro_interfaces__action__Toggle_SendGoal_Response__Sequence__are_equal(const xicro_interfaces__action__Toggle_SendGoal_Response__Sequence * lhs, const xicro_interfaces__action__Toggle_SendGoal_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!xicro_interfaces__action__Toggle_SendGoal_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
xicro_interfaces__action__Toggle_SendGoal_Response__Sequence__copy(
  const xicro_interfaces__action__Toggle_SendGoal_Response__Sequence * input,
  xicro_interfaces__action__Toggle_SendGoal_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(xicro_interfaces__action__Toggle_SendGoal_Response);
    xicro_interfaces__action__Toggle_SendGoal_Response * data =
      (xicro_interfaces__action__Toggle_SendGoal_Response *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!xicro_interfaces__action__Toggle_SendGoal_Response__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          xicro_interfaces__action__Toggle_SendGoal_Response__fini(&data[i]);
        }
        free(data);
        return false;
      }
    }
    output->data = data;
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!xicro_interfaces__action__Toggle_SendGoal_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__functions.h"

bool
xicro_interfaces__action__Toggle_GetResult_Request__init(xicro_interfaces__action__Toggle_GetResult_Request * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    xicro_interfaces__action__Toggle_GetResult_Request__fini(msg);
    return false;
  }
  return true;
}

void
xicro_interfaces__action__Toggle_GetResult_Request__fini(xicro_interfaces__action__Toggle_GetResult_Request * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
}

bool
xicro_interfaces__action__Toggle_GetResult_Request__are_equal(const xicro_interfaces__action__Toggle_GetResult_Request * lhs, const xicro_interfaces__action__Toggle_GetResult_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  return true;
}

bool
xicro_interfaces__action__Toggle_GetResult_Request__copy(
  const xicro_interfaces__action__Toggle_GetResult_Request * input,
  xicro_interfaces__action__Toggle_GetResult_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  return true;
}

xicro_interfaces__action__Toggle_GetResult_Request *
xicro_interfaces__action__Toggle_GetResult_Request__create()
{
  xicro_interfaces__action__Toggle_GetResult_Request * msg = (xicro_interfaces__action__Toggle_GetResult_Request *)malloc(sizeof(xicro_interfaces__action__Toggle_GetResult_Request));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(xicro_interfaces__action__Toggle_GetResult_Request));
  bool success = xicro_interfaces__action__Toggle_GetResult_Request__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
xicro_interfaces__action__Toggle_GetResult_Request__destroy(xicro_interfaces__action__Toggle_GetResult_Request * msg)
{
  if (msg) {
    xicro_interfaces__action__Toggle_GetResult_Request__fini(msg);
  }
  free(msg);
}


bool
xicro_interfaces__action__Toggle_GetResult_Request__Sequence__init(xicro_interfaces__action__Toggle_GetResult_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  xicro_interfaces__action__Toggle_GetResult_Request * data = NULL;
  if (size) {
    data = (xicro_interfaces__action__Toggle_GetResult_Request *)calloc(size, sizeof(xicro_interfaces__action__Toggle_GetResult_Request));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = xicro_interfaces__action__Toggle_GetResult_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        xicro_interfaces__action__Toggle_GetResult_Request__fini(&data[i - 1]);
      }
      free(data);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
xicro_interfaces__action__Toggle_GetResult_Request__Sequence__fini(xicro_interfaces__action__Toggle_GetResult_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      xicro_interfaces__action__Toggle_GetResult_Request__fini(&array->data[i]);
    }
    free(array->data);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

xicro_interfaces__action__Toggle_GetResult_Request__Sequence *
xicro_interfaces__action__Toggle_GetResult_Request__Sequence__create(size_t size)
{
  xicro_interfaces__action__Toggle_GetResult_Request__Sequence * array = (xicro_interfaces__action__Toggle_GetResult_Request__Sequence *)malloc(sizeof(xicro_interfaces__action__Toggle_GetResult_Request__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = xicro_interfaces__action__Toggle_GetResult_Request__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
xicro_interfaces__action__Toggle_GetResult_Request__Sequence__destroy(xicro_interfaces__action__Toggle_GetResult_Request__Sequence * array)
{
  if (array) {
    xicro_interfaces__action__Toggle_GetResult_Request__Sequence__fini(array);
  }
  free(array);
}

bool
xicro_interfaces__action__Toggle_GetResult_Request__Sequence__are_equal(const xicro_interfaces__action__Toggle_GetResult_Request__Sequence * lhs, const xicro_interfaces__action__Toggle_GetResult_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!xicro_interfaces__action__Toggle_GetResult_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
xicro_interfaces__action__Toggle_GetResult_Request__Sequence__copy(
  const xicro_interfaces__action__Toggle_GetResult_Request__Sequence * input,
  xicro_interfaces__action__Toggle_GetResult_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(xicro_interfaces__action__Toggle_GetResult_Request);
    xicro_interfaces__action__Toggle_GetResult_Request * data =
      (xicro_interfaces__action__Toggle_GetResult_Request *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!xicro_interfaces__action__Toggle_GetResult_Request__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          xicro_interfaces__action__Toggle_GetResult_Request__fini(&data[i]);
        }
        free(data);
        return false;
      }
    }
    output->data = data;
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!xicro_interfaces__action__Toggle_GetResult_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `result`
// already included above
// #include "xicro_interfaces/action/detail/toggle__functions.h"

bool
xicro_interfaces__action__Toggle_GetResult_Response__init(xicro_interfaces__action__Toggle_GetResult_Response * msg)
{
  if (!msg) {
    return false;
  }
  // status
  // result
  if (!xicro_interfaces__action__Toggle_Result__init(&msg->result)) {
    xicro_interfaces__action__Toggle_GetResult_Response__fini(msg);
    return false;
  }
  return true;
}

void
xicro_interfaces__action__Toggle_GetResult_Response__fini(xicro_interfaces__action__Toggle_GetResult_Response * msg)
{
  if (!msg) {
    return;
  }
  // status
  // result
  xicro_interfaces__action__Toggle_Result__fini(&msg->result);
}

bool
xicro_interfaces__action__Toggle_GetResult_Response__are_equal(const xicro_interfaces__action__Toggle_GetResult_Response * lhs, const xicro_interfaces__action__Toggle_GetResult_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // status
  if (lhs->status != rhs->status) {
    return false;
  }
  // result
  if (!xicro_interfaces__action__Toggle_Result__are_equal(
      &(lhs->result), &(rhs->result)))
  {
    return false;
  }
  return true;
}

bool
xicro_interfaces__action__Toggle_GetResult_Response__copy(
  const xicro_interfaces__action__Toggle_GetResult_Response * input,
  xicro_interfaces__action__Toggle_GetResult_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // status
  output->status = input->status;
  // result
  if (!xicro_interfaces__action__Toggle_Result__copy(
      &(input->result), &(output->result)))
  {
    return false;
  }
  return true;
}

xicro_interfaces__action__Toggle_GetResult_Response *
xicro_interfaces__action__Toggle_GetResult_Response__create()
{
  xicro_interfaces__action__Toggle_GetResult_Response * msg = (xicro_interfaces__action__Toggle_GetResult_Response *)malloc(sizeof(xicro_interfaces__action__Toggle_GetResult_Response));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(xicro_interfaces__action__Toggle_GetResult_Response));
  bool success = xicro_interfaces__action__Toggle_GetResult_Response__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
xicro_interfaces__action__Toggle_GetResult_Response__destroy(xicro_interfaces__action__Toggle_GetResult_Response * msg)
{
  if (msg) {
    xicro_interfaces__action__Toggle_GetResult_Response__fini(msg);
  }
  free(msg);
}


bool
xicro_interfaces__action__Toggle_GetResult_Response__Sequence__init(xicro_interfaces__action__Toggle_GetResult_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  xicro_interfaces__action__Toggle_GetResult_Response * data = NULL;
  if (size) {
    data = (xicro_interfaces__action__Toggle_GetResult_Response *)calloc(size, sizeof(xicro_interfaces__action__Toggle_GetResult_Response));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = xicro_interfaces__action__Toggle_GetResult_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        xicro_interfaces__action__Toggle_GetResult_Response__fini(&data[i - 1]);
      }
      free(data);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
xicro_interfaces__action__Toggle_GetResult_Response__Sequence__fini(xicro_interfaces__action__Toggle_GetResult_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      xicro_interfaces__action__Toggle_GetResult_Response__fini(&array->data[i]);
    }
    free(array->data);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

xicro_interfaces__action__Toggle_GetResult_Response__Sequence *
xicro_interfaces__action__Toggle_GetResult_Response__Sequence__create(size_t size)
{
  xicro_interfaces__action__Toggle_GetResult_Response__Sequence * array = (xicro_interfaces__action__Toggle_GetResult_Response__Sequence *)malloc(sizeof(xicro_interfaces__action__Toggle_GetResult_Response__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = xicro_interfaces__action__Toggle_GetResult_Response__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
xicro_interfaces__action__Toggle_GetResult_Response__Sequence__destroy(xicro_interfaces__action__Toggle_GetResult_Response__Sequence * array)
{
  if (array) {
    xicro_interfaces__action__Toggle_GetResult_Response__Sequence__fini(array);
  }
  free(array);
}

bool
xicro_interfaces__action__Toggle_GetResult_Response__Sequence__are_equal(const xicro_interfaces__action__Toggle_GetResult_Response__Sequence * lhs, const xicro_interfaces__action__Toggle_GetResult_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!xicro_interfaces__action__Toggle_GetResult_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
xicro_interfaces__action__Toggle_GetResult_Response__Sequence__copy(
  const xicro_interfaces__action__Toggle_GetResult_Response__Sequence * input,
  xicro_interfaces__action__Toggle_GetResult_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(xicro_interfaces__action__Toggle_GetResult_Response);
    xicro_interfaces__action__Toggle_GetResult_Response * data =
      (xicro_interfaces__action__Toggle_GetResult_Response *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!xicro_interfaces__action__Toggle_GetResult_Response__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          xicro_interfaces__action__Toggle_GetResult_Response__fini(&data[i]);
        }
        free(data);
        return false;
      }
    }
    output->data = data;
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!xicro_interfaces__action__Toggle_GetResult_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__functions.h"
// Member `feedback`
// already included above
// #include "xicro_interfaces/action/detail/toggle__functions.h"

bool
xicro_interfaces__action__Toggle_FeedbackMessage__init(xicro_interfaces__action__Toggle_FeedbackMessage * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    xicro_interfaces__action__Toggle_FeedbackMessage__fini(msg);
    return false;
  }
  // feedback
  if (!xicro_interfaces__action__Toggle_Feedback__init(&msg->feedback)) {
    xicro_interfaces__action__Toggle_FeedbackMessage__fini(msg);
    return false;
  }
  return true;
}

void
xicro_interfaces__action__Toggle_FeedbackMessage__fini(xicro_interfaces__action__Toggle_FeedbackMessage * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
  // feedback
  xicro_interfaces__action__Toggle_Feedback__fini(&msg->feedback);
}

bool
xicro_interfaces__action__Toggle_FeedbackMessage__are_equal(const xicro_interfaces__action__Toggle_FeedbackMessage * lhs, const xicro_interfaces__action__Toggle_FeedbackMessage * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  // feedback
  if (!xicro_interfaces__action__Toggle_Feedback__are_equal(
      &(lhs->feedback), &(rhs->feedback)))
  {
    return false;
  }
  return true;
}

bool
xicro_interfaces__action__Toggle_FeedbackMessage__copy(
  const xicro_interfaces__action__Toggle_FeedbackMessage * input,
  xicro_interfaces__action__Toggle_FeedbackMessage * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  // feedback
  if (!xicro_interfaces__action__Toggle_Feedback__copy(
      &(input->feedback), &(output->feedback)))
  {
    return false;
  }
  return true;
}

xicro_interfaces__action__Toggle_FeedbackMessage *
xicro_interfaces__action__Toggle_FeedbackMessage__create()
{
  xicro_interfaces__action__Toggle_FeedbackMessage * msg = (xicro_interfaces__action__Toggle_FeedbackMessage *)malloc(sizeof(xicro_interfaces__action__Toggle_FeedbackMessage));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(xicro_interfaces__action__Toggle_FeedbackMessage));
  bool success = xicro_interfaces__action__Toggle_FeedbackMessage__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
xicro_interfaces__action__Toggle_FeedbackMessage__destroy(xicro_interfaces__action__Toggle_FeedbackMessage * msg)
{
  if (msg) {
    xicro_interfaces__action__Toggle_FeedbackMessage__fini(msg);
  }
  free(msg);
}


bool
xicro_interfaces__action__Toggle_FeedbackMessage__Sequence__init(xicro_interfaces__action__Toggle_FeedbackMessage__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  xicro_interfaces__action__Toggle_FeedbackMessage * data = NULL;
  if (size) {
    data = (xicro_interfaces__action__Toggle_FeedbackMessage *)calloc(size, sizeof(xicro_interfaces__action__Toggle_FeedbackMessage));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = xicro_interfaces__action__Toggle_FeedbackMessage__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        xicro_interfaces__action__Toggle_FeedbackMessage__fini(&data[i - 1]);
      }
      free(data);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
xicro_interfaces__action__Toggle_FeedbackMessage__Sequence__fini(xicro_interfaces__action__Toggle_FeedbackMessage__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      xicro_interfaces__action__Toggle_FeedbackMessage__fini(&array->data[i]);
    }
    free(array->data);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

xicro_interfaces__action__Toggle_FeedbackMessage__Sequence *
xicro_interfaces__action__Toggle_FeedbackMessage__Sequence__create(size_t size)
{
  xicro_interfaces__action__Toggle_FeedbackMessage__Sequence * array = (xicro_interfaces__action__Toggle_FeedbackMessage__Sequence *)malloc(sizeof(xicro_interfaces__action__Toggle_FeedbackMessage__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = xicro_interfaces__action__Toggle_FeedbackMessage__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
xicro_interfaces__action__Toggle_FeedbackMessage__Sequence__destroy(xicro_interfaces__action__Toggle_FeedbackMessage__Sequence * array)
{
  if (array) {
    xicro_interfaces__action__Toggle_FeedbackMessage__Sequence__fini(array);
  }
  free(array);
}

bool
xicro_interfaces__action__Toggle_FeedbackMessage__Sequence__are_equal(const xicro_interfaces__action__Toggle_FeedbackMessage__Sequence * lhs, const xicro_interfaces__action__Toggle_FeedbackMessage__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!xicro_interfaces__action__Toggle_FeedbackMessage__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
xicro_interfaces__action__Toggle_FeedbackMessage__Sequence__copy(
  const xicro_interfaces__action__Toggle_FeedbackMessage__Sequence * input,
  xicro_interfaces__action__Toggle_FeedbackMessage__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(xicro_interfaces__action__Toggle_FeedbackMessage);
    xicro_interfaces__action__Toggle_FeedbackMessage * data =
      (xicro_interfaces__action__Toggle_FeedbackMessage *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!xicro_interfaces__action__Toggle_FeedbackMessage__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          xicro_interfaces__action__Toggle_FeedbackMessage__fini(&data[i]);
        }
        free(data);
        return false;
      }
    }
    output->data = data;
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!xicro_interfaces__action__Toggle_FeedbackMessage__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}