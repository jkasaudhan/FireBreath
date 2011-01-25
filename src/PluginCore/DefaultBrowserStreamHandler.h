#pragma once
#ifndef DefaultBrowserStreamHandler_h__
#define DefaultBrowserStreamHandler_h__

/**********************************************************\ 
Original Author: Matthias (nitrogenycs)

Created:    Feb 28, 2010
License:    Dual license model; choose one of two:
            New BSD License
            http://www.opensource.org/licenses/bsd-license.php
            - or -
            GNU Lesser General Public License, version 2.1
            http://www.gnu.org/licenses/lgpl-2.1.html

Copyright 2010 PacketPass, Inc and the Firebreath development team
\**********************************************************/

#include "BrowserStream.h"

namespace FB {
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    /// @class  DefaultBrowserStreamHandler
    ///
    /// @brief Simple implementation of a stream event handler from which you can derive your own stream
    ///        events handler
    ///
    /// This class is a convenience implementation of an event handler for the stream events generated by
    /// BrowserStream.
    /// You can derive your own stream event handler class from this class and override only the onStream*
    /// methods you'll need. Then attach instances of your custom class to a BrowserStream instance.
    /// 
    /// @author Matthias
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    class DefaultBrowserStreamHandler : public PluginEventSink
    {
    public:
        BEGIN_PLUGIN_EVENT_MAP()
            EVENTTYPE_CASE(FB::StreamCreatedEvent, onStreamCreated, FB::BrowserStream)
            EVENTTYPE_CASE(FB::StreamDestroyedEvent, onStreamDestroyed, FB::BrowserStream)
            EVENTTYPE_CASE(FB::StreamFailedOpenEvent, onStreamFailedOpen, FB::BrowserStream)
            EVENTTYPE_CASE(FB::StreamOpenedEvent, onStreamOpened, FB::BrowserStream)
            EVENTTYPE_CASE(FB::StreamDataArrivedEvent, onStreamDataArrived, FB::BrowserStream)
            EVENTTYPE_CASE(FB::StreamCompletedEvent, onStreamCompleted, FB::BrowserStream)
        END_PLUGIN_EVENT_MAP()

        ////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @fn DefaultBrowserStreamHandler::DefaultBrowserStreamHandler()
        ///
        /// @brief  Default constructor.
        ///
        /// @author Matthias
        ////////////////////////////////////////////////////////////////////////////////////////////////////
        DefaultBrowserStreamHandler();

        ////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @fn virtual DefaultBrowserStreamHandler::~DefaultBrowserStreamHandler()
        ///
        /// @brief  Destructor.
        ///
        /// @author Matthias
        ////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual
        ~DefaultBrowserStreamHandler();

        ////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @fn virtual bool DefaultBrowserStreamHandler::onStreamCreated(FB::StreamCreatedEvent *evt, FB::BrowserStream * Stream);
        ///
        /// @brief  Called when the stream was created.
        ///
        /// @author Matthias
        ////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual bool onStreamCreated(FB::StreamCreatedEvent *evt, FB::BrowserStream * Stream);

        ////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @fn virtual bool DefaultBrowserStreamHandler::onStreamDestroyed(FB::StreamDestroyedEvent *evt, FB::BrowserStream * Stream);
        ///
        /// @brief  Called when the stream is destroyed.
        ///
        /// @author Matthias
        ////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual bool onStreamDestroyed(FB::StreamDestroyedEvent *evt, FB::BrowserStream *);

        ////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @fn virtual bool DefaultBrowserStreamHandler::onStreamDataArrived(FB::StreamDataArrivedEvent *evt, FB::BrowserStream * Stream);
        ///
        /// @brief  Called when data arrives.
        ///
        /// @author Matthias
        ////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual bool onStreamDataArrived(FB::StreamDataArrivedEvent *evt, FB::BrowserStream *);

        ////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @fn virtual bool DefaultBrowserStreamHandler::onStreamFailedOpen(FB::StreamFailedOpenEvent *evt, FB::BrowserStream * Stream);
        ///
        /// @brief  Called when the stream failed to open.
        ///
        /// @author Matthias
        ////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual bool onStreamFailedOpen(FB::StreamFailedOpenEvent *evt, FB::BrowserStream *);

        ////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @fn virtual bool DefaultBrowserStreamHandler::onStreamOpened(FB::StreamOpenedEvent *evt, FB::BrowserStream * Stream);
        ///
        /// @brief  Called when the stream was opened successfully.
        ///
        /// @author Matthias
        ////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual bool onStreamOpened(FB::StreamOpenedEvent *evt, FB::BrowserStream *);

        ////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @fn virtual bool DefaultBrowserStreamHandler::onStreamCompleted(FB::StreamCompletedEvent *evt, FB::BrowserStream * Stream);
        ///
        /// @brief  Called when the stream finished downloading successfully.
        ///
        /// @author Matthias
        ////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual bool onStreamCompleted(FB::StreamCompletedEvent *evt, FB::BrowserStream *);

        ////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @fn virtual FB::BrowserStream* DefaultBrowserStreamHandler::getStream() const;
        ///
        /// @brief  Call to get the stream associated with this handler. Returns empty shared_ptr if none.
        ///
        /// @author Matthias
        ////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual const FB::BrowserStreamPtr& getStream() const;

    protected:
        ////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @fn virtual void DefaultBrowserStreamHandler::setStream(FB::BrowserStream* stream);
        ///
        /// @brief  Call to set the stream associated with this handler.
        ///
        /// @author Matthias
        ////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual void setStream(const FB::BrowserStreamPtr& stream);

        ////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @fn virtual void DefaultBrowserStreamHandler::clearStream()
        ///
        /// @brief  Call to clear the stream associated with this handler.
        ///
        /// @author Richard Bateman
        ////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual void clearStream();

        BrowserStreamPtr stream;  ///< stream instance, don't use yourself
    };
}
#endif // DefaultBrowserStreamHandler_h__