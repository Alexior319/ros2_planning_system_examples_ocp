// Copyright 2019 Intelligent Robotics Lab
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <string>
#include <iostream>

#include "behavior_tree_nodes/CloseGripper.hpp"

#include "behaviortree_cpp_v3/behavior_tree.h"
#include "behaviortree_cpp_v3/bt_factory.h"

namespace plansys2_bt_example
{

CloseGripper::CloseGripper(const std::string & name)
: BT::ActionNodeBase(name, {}), counter_(0)
{
}

void
CloseGripper::halt()
{
  std::cout << "CloseGripper halt" << std::endl;
}

BT::NodeStatus
CloseGripper::tick()
{
  std::cout << "CloseGripper tick " << counter_ << std::endl;

  counter_++;

  if (counter_++ < 5) {
    return BT::NodeStatus::RUNNING;
  } else {
    return BT::NodeStatus::SUCCESS;
  }
}

}  // namespace plansys2_bt_example
