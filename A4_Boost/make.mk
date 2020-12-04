BOOST := $(HOME)/work/boost_1_57_0
CFLAGS := -I $(BOOST)
ifdef SHARED_LIBS
	LFLAGS := -L $(BOOST)/$(SHARED_LIBS) $(BOOST_LIBS)
endif

export CFLAGS
export LFLAGS
