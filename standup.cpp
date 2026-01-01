#include "standup.h"
#include "common/macros.h"
#include "common/nndef.h"
#include "gameroot.h"
#include "context/context.h"
#include "Comm/ITableGame.h"
#include "config/gameconfig.h"
#include "utils/tarslog.h"
#include "context/context.h"
#include "message/sendclientmessage.h"

using namespace nndef;

namespace majong
{
    namespace logic
    {
        namespace roomlogic
        {
            int StandUp(void const *p, GameRoot *root)
            {
                PERFSTATS_ENTRY();
                __TRY__
                
               
                __CATCH__
                PERFSTATS_EXIT();
                return 0;
            }
        }
    }
}
