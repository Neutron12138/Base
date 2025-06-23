#pragma once

// core

#include "core.hpp"

// others

#include "others/application.hpp"
#include "others/notifiable.hpp"
#include "others/resource.hpp"
#include "others/named_object.hpp"
#include "others/logger.hpp"

#ifndef BASE_NO_IMPL
#include "others/logger.cpp"
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
