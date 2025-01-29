#pragma once

namespace registration
{
    enum Choice
    {
        NONE   = 0,
        CREATE = 1,
        REMOVE = 2,
        UPDATE = 3,
        VIEW   = 4,
        EXIT   = 5
    };

    enum UpdateChoice
    {
        UPDATE_ID = 1,
        UPDATE_NAME = 2
    };
}

