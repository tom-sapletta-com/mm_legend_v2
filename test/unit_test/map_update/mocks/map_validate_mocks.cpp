/*
 * file:    map_mocks.cpp
 * author:  GAndaLF
 * brief:   Mock functions for map module.
 */

#include "platform_specific.h"

extern "C"
{
    #include "map/map.h"
    #include "map/map_internal.h"
}

#include "map_validate_mocks.hpp"

static MapValidateWallMock *mapValidateWallLeftMock = nullptr;
static MapValidateWallMock *mapValidateWallRightMock = nullptr;
static MapValidateWallMock *mapValidateWallTopMock = nullptr;
static MapValidateWallMock *mapValidateWallBottomMock = nullptr;

int32_t MapValidateWallMock::getCount()
{
    return cnt_;
}

int32_t MapValidateWallMock::getArg1()
{
    return arg1_;
}

map_wall_state_t MapValidateWallMock::getArg2()
{
    return arg2_;
}

void MapValidateWallMock::call(int32_t cell_id, map_wall_state_t wall_state)
{
    cnt_++;

    arg1_ = cell_id;
    arg2_ = wall_state;
}

void mapValidateWallLeftMockSet(MapValidateWallMock *mock)
{
    mapValidateWallLeftMock = mock;
}

void map_validate_wall_left(int32_t cell_id, map_wall_state_t wall_state)
{
    if (nullptr != mapValidateWallLeftMock)
    {
        return mapValidateWallLeftMock->call(cell_id, wall_state);
    }
}

void mapValidateWallRightMockSet(MapValidateWallMock *mock)
{
    mapValidateWallRightMock = mock;
}

void map_validate_wall_right(int32_t cell_id, map_wall_state_t wall_state)
{
    if (nullptr != mapValidateWallRightMock)
    {
        return mapValidateWallRightMock->call(cell_id, wall_state);
    }
}

void mapValidateWallTopMockSet(MapValidateWallMock *mock)
{
    mapValidateWallTopMock = mock;
}

void map_validate_wall_top(int32_t cell_id, map_wall_state_t wall_state)
{
    if (nullptr != mapValidateWallTopMock)
    {
        return mapValidateWallTopMock->call(cell_id, wall_state);
    }
}

void mapValidateWallBottomMockSet(MapValidateWallMock *mock)
{
    mapValidateWallBottomMock = mock;
}

void map_validate_wall_bottom(int32_t cell_id, map_wall_state_t wall_state)
{
    if (nullptr != mapValidateWallBottomMock)
    {
        return mapValidateWallBottomMock->call(cell_id, wall_state);
    }
}
