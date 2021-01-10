
#pragma once

#include <common/game_state.hpp>
#include <iostream>
#include <vector>
#include <string>
#include <Poco/Net/ServerSocket.h>
#include <Poco/Net/HTTPServer.h>
#include <Poco/Net/HTTPRequestHandler.h>
#include <Poco/Net/HTTPRequestHandlerFactory.h>
#include <Poco/Net/HTTPResponse.h>
#include <Poco/Net/HTTPServerRequest.h>
#include <Poco/Net/HTTPServerResponse.h>
#include <Poco/Util/ServerApplication.h>


using namespace Poco::Net;
using namespace Poco::Util;
using namespace std;

class MyRequestHandler : public HTTPRequestHandler
{
public:
  virtual void handleRequest(HTTPServerRequest &req, HTTPServerResponse &resp)
  {
    resp.setStatus(HTTPResponse::HTTP_OK);
    resp.setContentType("text/html");

    ostream& out = resp.send();
    if(req.getURI()=="/common_data"){
      out<<server::GlobalRoundState;
    }
    out.flush();

  }

private:
  static int count;
};

int MyRequestHandler::count = 0;

class MyRequestHandlerFactory : public HTTPRequestHandlerFactory
{
public:
  virtual HTTPRequestHandler* createRequestHandler(const HTTPServerRequest & request)
  {
    return new MyRequestHandler;
  }
};

class MyServerApp : public ServerApplication
{
protected:
  int main(const vector<string> &)
  {
    HTTPServer s(new MyRequestHandlerFactory, ServerSocket(9090), new HTTPServerParams);

    s.start();
    cout << endl << "Server started" << endl;

    waitForTerminationRequest();  // wait for CTRL-C or kill

    cout << endl << "Shutting down..." << endl;
    s.stop();

    return Application::EXIT_OK;
  }
};

  // void onRequest(const Http::Request& request, Http::ResponseWriter writer) override{
  //   //std::cout<<a.body();
  //   if (request.resource() == "/common_data" && request.method() == Http::Method::Get) {
  //       std::stringstream s;
  //       s<<server::GlobalRoundState;
  //       writer.send(Http::Code::Ok, s.str());  
  //   }
  //   else if (request.resource() == "/1" && request.method() == Http::Method::Post)
  //           writer.send(Http::Code::Ok, "You posted");
  //   else if (request.resource() == "/1" && request.method() == Http::Method::Get) 
  //     writer.send(Http::Code::Ok, "You are player A take your data");
  //   else if (request.resource() == "/2" && request.method() == Http::Method::Get) 
  //     writer.send(Http::Code::Ok, "You are player B take your data");
  //   else if (request.resource() == "/3" && request.method() == Http::Method::Get)
  //     writer.send(Http::Code::Ok,"You are player C take your data");
  //   else
  //     writer.send(Http::Code::Ok, "Not a valid request");
  // }
