/*
 *
 * NOTE: this code comes from:
 * https://stackoverflow.com/questions/10538444/do-you-know-of-a-c-macro-to-compute-unix-time-and-date
 * authored by:
 * Alexis Wilke
 * 
 * NOTE by Jean Rabault START: ---------------------------------------------------------------------
 * This should take correctly care of the Gregorian calendar 29th February, 100 and 400 second leaps.
 * This should correspond to the POSIX/UNIX definition of timestamp.
 * NOTE by Jean Rabault END  : ---------------------------------------------------------------------
 *  
 */

#ifndef GET_UNIX_TIMESTAMP_
#define GET_UNIX_TIMESTAMP_

// helper (Days in February)
#define _SNAP_UNIX_TIMESTAMP_FDAY(year) \
    (((year) % 400) == 0 ? 29LL : \
        (((year) % 100) == 0 ? 28LL : \
            (((year) % 4) == 0 ? 29LL : \
                28LL)))

// helper (Days in the year)
#define _SNAP_UNIX_TIMESTAMP_YDAY(year, month, day) \
    ( \
        /* January */    day \
        /* February */ + (month >=  2 ? 31LL : 0LL) \
        /* March */    + (month >=  3 ? _SNAP_UNIX_TIMESTAMP_FDAY(year) : 0LL) \
        /* April */    + (month >=  4 ? 31LL : 0LL) \
        /* May */      + (month >=  5 ? 30LL : 0LL) \
        /* June */     + (month >=  6 ? 31LL : 0LL) \
        /* July */     + (month >=  7 ? 30LL : 0LL) \
        /* August */   + (month >=  8 ? 31LL : 0LL) \
        /* September */+ (month >=  9 ? 31LL : 0LL) \
        /* October */  + (month >= 10 ? 30LL : 0LL) \
        /* November */ + (month >= 11 ? 31LL : 0LL) \
        /* December */ + (month >= 12 ? 30LL : 0LL) \
    )

#define SNAP_UNIX_TIMESTAMP(year, month, day, hour, minute, second) \
    ( /* time */ second \
                + minute * 60LL \
                + hour * 3600LL \
    + /* year day (month + day) */ (_SNAP_UNIX_TIMESTAMP_YDAY(year, month, day) - 1) * 86400LL \
    + /* year */ (year - 1970LL) * 31536000LL \
                + ((year - 1969LL) / 4LL) * 86400LL \
                - ((year - 1901LL) / 100LL) * 86400LL \
                + ((year - 1601LL) / 400LL) * 86400LL \
    )

#endif