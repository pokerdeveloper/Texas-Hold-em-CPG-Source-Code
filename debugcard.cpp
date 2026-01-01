#include "common/macros.h"
#include "common/nndef.h"
#include "gameroot.h"
#include "logic/roomlogic/core/debugcard.h"
#include "context/context.h"
#include "Comm/ITableGame.h"
#include "config/gameconfig.h"
#include "utils/tarslog.h"
#include "process/process.h"
#include "context/context.h"

using namespace nndef;

namespace majong
{
    namespace logic
    {
        namespace roomlogic
        {
            int DebugCard(void const *p, GameRoot *root)
            {
                PERFSTATS_ENTRY();
                __TRY__

                using namespace RoomSo;
                using namespace context;

                TGAME_DebugCard const *nnrs = static_cast<TGAME_DebugCard const *>(p);
                DLOG_TRACE("roomid:"<<root->roomid()<<", "<<"DebugCard: " << printTars(*nnrs));

                root->con->clearDebugCards();

                std::set<string> sdebugcard;
                auto vCommDebugCard = tars::TC_Common::sepstr<string>(nnrs->comm_debug_card, ",");
                for(auto card : vCommDebugCard)
                {
                    if(checkCard(card, sdebugcard))
                    {
                        root->con->addDebugCard(-1, atoi(card.c_str()));
                        DLOG_TRACE("roomid:"<<root->roomid()<<", "<<"DebugCard. cid: -1, card: " << card);
                    }
                }
                for(auto cardItem : nnrs->seat_debug_card)
                {
                    auto vSeatDebugCard = tars::TC_Common::sepstr<string>(cardItem.second, ",");
                    for(auto card : vSeatDebugCard)
                    {
                        if(checkCard(card, sdebugcard))
                        {
                            root->con->addDebugCard(cardItem.first, atoi(card.c_str()));
                            DLOG_TRACE("roomid:"<<root->roomid()<<", "<<"DebugCard. cid: "<< cardItem.first <<", card: " << card);
                        }  
                    } 
                }

                __CATCH__
                PERFSTATS_EXIT();
                return 0;
            }

            bool checkCard(string card, std::set<string>& sdebugcard)
            {
                int pre_card_count = sdebugcard.size();
                sdebugcard.insert(card);
                if(sdebugcard.size() - pre_card_count != 1)
                {
                    return false;
                }

                int trancard = atoi(card.c_str());
                if(trancard < 0 || 71 < trancard)
                {
                    return false;
                }
                return true;
            }
        }
    }
}
