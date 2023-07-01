#include "en.h"
int playerimg;//ƒvƒŒƒCƒ„[‚Ì‰æ‘œ
//‰~‚Ì“–‚½‚è”»’èŠÖ”
bool isHit(En en1, En en2)
{
	//“ñ‚Â‚Ì‰~‚Ì“–‚½‚è”»’è
	double dx = en1.x - en2.x;//‰¡‚Ì‹——£
	double dy = en1.y - en2.y;//c‚Ì‹——£
	double r2 = en1.r + en2.r;//”¼Œa‚Ì‡Z

	if (dx * dx + dy * dy < r2 * r2)
	{
		//“–‚½‚Á‚Ä‚¢‚é
		return true;
	}
	//“–‚½‚Á‚Ä‚¢‚È‚¢
	return false;
}