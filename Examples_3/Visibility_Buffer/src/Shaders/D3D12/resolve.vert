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

struct PsIn
{
    float4 position : SV_Position;
};

PsIn main(uint vertexID : SV_VertexID)
{
	// Produce a fullscreen triangle	
    PsIn Out;
    Out.position.x = (vertexID == 2) ? 3.0 : -1.0;
    Out.position.y = (vertexID == 0) ? -3.0 : 1.0;
    Out.position.zw = float2(1,1);
    return Out;
}
