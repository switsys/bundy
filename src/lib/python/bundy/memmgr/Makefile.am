SUBDIRS = . tests

python_PYTHON = __init__.py builder.py datasrc_info.py logger.py

pythondir = $(pyexecdir)/bundy/memmgr

BUILT_SOURCES = $(PYTHON_LOGMSGPKG_DIR)/work/libmemmgr_messages.py

nodist_pylogmessage_PYTHON = $(PYTHON_LOGMSGPKG_DIR)/work/libmemmgr_messages.py

pylogmessagedir = $(pyexecdir)/bundy/log_messages/

CLEANFILES = $(PYTHON_LOGMSGPKG_DIR)/work/libmemmgr_messages.py
CLEANFILES += $(PYTHON_LOGMSGPKG_DIR)/work/libmemmgr_messages.pyc

EXTRA_DIST = libmemmgr_messages.mes

$(PYTHON_LOGMSGPKG_DIR)/work/libmemmgr_messages.py : libmemmgr_messages.mes
	$(top_builddir)/src/lib/log/compiler/message \
	-d $(PYTHON_LOGMSGPKG_DIR)/work -p $(srcdir)/libmemmgr_messages.mes

CLEANDIRS = __pycache__

clean-local:
	rm -rf $(CLEANDIRS)
