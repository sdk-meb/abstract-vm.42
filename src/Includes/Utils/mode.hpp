#ifndef __STAT_MODE_
# define __STAT_MODE_

#include <iostream>

// Development, Test, Debuging, Product

#if defined(Development)
# define throwgh(__none_) void(__none_);
# define __ca_tch(__none_) void(__none_);

#elif defined(Test)
# define throwgh(__none_) void(__none_);
# define __ca_tch(__none_) void(__none_);

#elif defined(Debuging)

# define throwgh(func_name) std::cerr << func_name;
# define __ca_tch(ex_type) std::cerr << " ca_tch " << ex_type << std::endl;

#elif defined(Product)

# define throwgh(__none_) void(__none_);
# define __ca_tch(__none_) void(__none_);
#endif // __STATS

#endif // __STAT_MODE_