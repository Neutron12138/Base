#pragma once

// C++版本必须在C++17以上
#if __cplusplus < 201703L
#error The C++ version is too low, at least it should be C++ 17
#endif

// core

#include "core.hpp"

// misc

#include "misc/application.hpp"
#include "misc/notifiable.hpp"
#include "misc/resource.hpp"
#include "misc/named_object.hpp"
#include "misc/logger.hpp"

#include "misc/logger.cpp"

// event

#include "event/event.hpp"
#include "event/event_handler.hpp"

// node

#include "node/node.hpp"
#include "node/tree_node.hpp"
#include "node/node_tree.hpp"

#include "node/node.cpp"
#include "node/tree_node.cpp"
#include "node/node_tree.cpp"

// process

#include "process/time_manager.hpp"
#include "process/frame_manager.hpp"
#include "process/processable.hpp"
#include "process/process_manager.hpp"

#include "process/frame_manager.cpp"
#include "process/processable.cpp"
#include "process/process_manager.cpp"

// image

#include "image/pixel.hpp"
#include "image/base_image.hpp"
#include "image/fast_image.hpp"

// meta

#include "meta/meta_base.hpp"
#include "meta/field_base.hpp"
#include "meta/method_base.hpp"
#include "meta/global_field.hpp"
#include "meta/global_method.hpp"
#include "meta/member_field.hpp"
#include "meta/member_method.hpp"
#include "meta/member_field_offset.hpp"

// reflection

#include "reflection/class_info.hpp"
#include "reflection/class_info_base_register.hpp"
#include "reflection/class_info_register.hpp"
#include "reflection/dynamic_class_info_register.hpp"
#include "reflection/class_db.hpp"

#include "reflection/class_info.cpp"
