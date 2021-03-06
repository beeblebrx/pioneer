#ifndef _DELETEEMITTER_H
#define _DELETEEMITTER_H

// inherit from this class to be able to get notifications when an object is
// destroyed. the LuaObject tracking layer uses this to properly "forget"
// about objects that are currently exposed to lua

// including sigc++ directly so we don't get circular dependencies
#include <sigc++/sigc++.h>

class DeleteEmitter {
public:
	DeleteEmitter() {}
	virtual ~DeleteEmitter() {
		onDelete.emit();
	}
	sigc::signal<void> onDelete;

private:
    // sigc++ signals cannot be copied, but long-standing design flaw means
    // they don't have a private copy constructor. we protect them ourselves
	DeleteEmitter(const DeleteEmitter &) {}
};

#endif
