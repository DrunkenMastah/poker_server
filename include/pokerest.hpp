
#pragma once

#include "pistache/endpoint.h"
#include <pistache/http_defs.h>

#include <iostream>


using namespace Pistache;

struct pokerest : public Http::Handler {
  HTTP_PROTOTYPE(pokerest)
  void onRequest(const Http::Request& request, Http::ResponseWriter writer) override{
    //std::cout<<a.body();
    if (request.resource() == "/A" && request.method() == Http::Method::Get) 
      writer.send(Http::Code::Ok, "You are player A take your data");
    else if (request.resource() == "/B" && request.method() == Http::Method::Get) 
      writer.send(Http::Code::Ok, "You are player B take your data");
    else if (request.resource() == "/C" && request.method() == Http::Method::Get)
      writer.send(Http::Code::Ok,"You are player C take your data");
    else
      writer.send(Http::Code::Ok, "Not a valid request");
  }
};
