extern "C" {
#include "TH.h"
#include "luaT.h"
}

#include "stdint.h"

extern "C" {
#include "mccodimage.h"
#include "mcimage.h"
#include "jcgraphes.h"
#include "jcimage.h"
#include "jccodimage.h"
#include "jccomptree.h"
#include "llabelextrema.h"
#include "lwshedtopo.h"
#include "lsaliency.h"
#include "lhierarchie.h"
#include "lattribheight.h"
#include "MSF_utils.h"
#include "llpeGA.h"
#include "lga2khalimsky.h"
#include "lppm2GA.h"
#include "mcweightgraph.h"
#include "sjcomptree.h"
#include "overlap.h"
}

#include "powerwatershed.h"
#include "set.h"
#include "mergetree.h"
#include "maxflow.h"

#include <vector>
#include <map>
#include <boost/pending/disjoint_sets.hpp>

#define torch_(NAME) TH_CONCAT_3(torch_, Real, NAME)
#define torch_Tensor TH_CONCAT_STRING_3(torch., Real, Tensor)
#define imgraph_(NAME) TH_CONCAT_3(imgraph_, Real, NAME)
#define nn_(NAME) TH_CONCAT_3(nn_, Real, NAME)

#include "generic/imgraph.c"
#include "THGenerateFloatTypes.h"

#include "generic/MalisCriterion.c"
#include "THGenerateFloatTypes.h"

extern "C" {
  DLL_EXPORT int luaopen_libimgraph(lua_State *L)
  {
    imgraph_FloatInit(L);
    imgraph_DoubleInit(L);

    nn_FloatMalisCriterion_init(L);
    nn_DoubleMalisCriterion_init(L);

    return 1;
  }
}
