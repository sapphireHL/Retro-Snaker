#include "object.h"

bool operator == (const Position A, const Position B){
	return A.x == B.x&&A.y == B.y;
}