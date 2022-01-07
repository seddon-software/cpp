 	Description
std::ranges::input_range 	                can be iterated from beginning to end at least once
std::ranges::forward_range 	                can be iterated from beginning to end multiple times
std::ranges::bidirectional_range 	        iterator can also move backwards with --
std::ranges::random_access_range 	        you can jump to elements in constant-time with []
std::ranges::contiguous_range 	            elements are always stored consecutively in memory

 	                            std::forward_list 	std::list 	std::deque 	std::array 	std::vector
std::ranges::input_range 	         ✅ 	            ✅ 	        ✅ 	        ✅ 	        ✅
std::ranges::forward_range 	         ✅ 	            ✅ 	        ✅ 	        ✅ 	        ✅
std::ranges::bidirectional_range 		             ✅ 	         ✅ 	         ✅ 	         ✅
std::ranges::random_access_range 			                      ✅ 	      ✅ 	      ✅
std::ranges::contiguous_range 				                                   ✅ 	       ✅
