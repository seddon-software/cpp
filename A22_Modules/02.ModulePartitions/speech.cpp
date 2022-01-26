/*
 *  Module units whose declaration has the keyword export are module interface units. Other module units 
 *  are called module implementation units. 

 *  This module interface units has two partitions (in separate files).  These partitions contain the 
 *  code for this module.
 */

export module speech;

// export module interface partitions (every partition must be exported or the program is ill formed)
export import :english;
export import :spanish;
