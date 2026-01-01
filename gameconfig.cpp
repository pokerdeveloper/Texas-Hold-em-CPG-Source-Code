#include "common/macros.h"
#include "gameroot.h"
#include "logic/roomlogic/core/gameconfig.h"
#include "config/gameconfig.h"
#include "process/process.h"
#include "context/context.h"
#include "utils/tarslog.h"

namespace majong
{
    namespace logic
    {
        namespace roomlogic
        {
            void GameConfig(void const *p, GameRoot *root)
            {
                PERFSTATS_ENTRY();
                __TRY__

                //DLOG_TRACE("roomid:"<<root->roomid()<<", "<<"GameConfig.");

                using namespace config;
                using namespace context;
                using namespace process;

                //
                root->cfg->loadRoomConfig(p);
                root->cfg->printRoomConfig();

                //
                root->con->gameInit();
                root->pro->gameInit();

                __CATCH__
                PERFSTATS_EXIT();
            }
        }
    }
}
