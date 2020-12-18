/*
 * Copyright (c) 2018-2021 The Forge Interactive Inc.
 *
 * This file is part of The-Forge
 * (see https://github.com/ConfettiFX/The-Forge).
 *
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
*/

#include "MoveComponent.h"
#include "../Representations/MoveRepresentation.h"

#include "../../../../../Common_3/OS/Interfaces/IMemory.h"    // Must be the last include in a cpp file

FORGE_IMPLEMENT_COMPONENT(MoveComponent)

// Based on: https://github.com/aras-p/dod-playground
static float RandomFloat01() { return (float)rand() / (float)RAND_MAX; }
static float RandomFloat(float from, float to) { return RandomFloat01() * (to - from) + from; }

MoveComponent::MoveComponent()
{

}

void MoveComponent::Initialize(float minSpeed, float maxSpeed)
{
	// random angle
	float angle = RandomFloat01() * 3.1415926f * 2;
	// random movement speed between given min & max
	float speed = RandomFloat(minSpeed, maxSpeed);
	// velocity x & y components
	velx = cosf(angle) * speed;
	vely = sinf(angle) * speed;
}