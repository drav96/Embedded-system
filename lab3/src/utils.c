

#include "utils.h"

float ConvertValueFromToRange(float val,float minFromRange,float maxFromRange,float minToRange,float maxToRange){
	return (val - minFromRange) * (maxToRange - minToRange) / (maxFromRange - minFromRange) + minToRange;
}