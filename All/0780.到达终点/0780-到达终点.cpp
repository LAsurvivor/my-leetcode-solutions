class Solution {
using pii = pair<int, int>;
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        // if (sx == tx && sy == ty) return true;
        // if (sx > tx || sy > ty) return false;

        // if (reachingPoints(sx + sy, sy, tx, ty) ||
        //     reachingPoints(sx, sx + sy, tx, ty)) return true;
        // return false;

        while (tx > sx && ty > sy && tx != ty) {
            if (tx > ty) tx %= ty;
            else ty %= tx;
        }
        if (tx == sx && ty == sy) return true;
        if (tx == sx) return ty > sy && (ty - sy) % tx == 0;
        if (ty == sy) return tx > sx && (tx - sx) % ty == 0;
        return false;
    }
};