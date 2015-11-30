#ifndef TSHOOT_HPP
#define TSHOOT_HPP
#include "tactic.h"
#include "skills/skillSet.h"
#include "krssg_ssl_msgs/BeliefState.h"
#include "ssl_common/config.h"
#include <sys/time.h>
#include <unistd.h>
#include "tactic_factory.h"
namespace Strategy  
{
  class TShoot: public Tactic
  {
  public:

    TShoot(int botID);

    ~TShoot();
    virtual bool isCompleted(const BeliefState &bs) const ;

    virtual bool isActiveTactic(void) const;
//CHOOSEbEST bOT AND the giving of parameters for going to the required point needs to be entered
//Choose best bot also needs to get the params that the tactic has in order to choose the best bot....

    virtual int chooseBestBot(const BeliefState &bs, std::list<int>& freeBots, const Param& tParam, int prevID = -1) const;

    virtual Vector2D<int> getOppGoalie(const BeliefState &state);
   

    virtual gr_Robot_Command execute(const BeliefState &state, const Param& tParam);

    virtual Tactic::Param paramFromJSON(string json);
    virtual string paramToJSON(Tactic::Param p);
    
  }; // class TShoot
  // registering tactic with factory:
  REGISTER_TACTIC(TShoot)
} // namespace Strategy
#endif