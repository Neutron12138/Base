#pragma once

// core

#include "core.hpp"

// misc

#include "misc/application.hpp"
#include "misc/notifiable.hpp"
#include "misc/resource.hpp"
#include "misc/named_object.hpp"
#include "misc/logger.hpp"

#ifndef BASE_NO_IMPL
#include "misc/logger.cpp"
#endif

// event

#include "event/event.hpp"
#include "event/event_handler.hpp"

// node

#include "node/node.hpp"
#include "node/tree_node.hpp"
#include "node/node_tree.hpp"

#ifndef BASE_NO_IMPL
#include "node/node.cpp"
#include "node/tree_node.cpp"
#include "node/node_tree.cpp"
#endif

// process

#include "process/time_manager.hpp"
#include "process/frame_manager.hpp"
#include "process/processable.hpp"
#include "process/process_manager.hpp"

#ifndef BASE_NO_IMPL
#include "process/frame_manager.cpp"
#include "process/processable.cpp"
#include "process/process_manager.cpp"
#endif

// image

#include "image/pixel.hpp"
#include "image/base_image.hpp"
#include "image/fast_image.hpp"

// reflection

#include "meta/field_base.hpp"
#include "meta/method_base.hpp"
#include "meta/field.hpp"
#include "meta/method.hpp"
#include "meta/member_field.hpp"
#include "meta/member_method.hpp"
