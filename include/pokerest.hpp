
#pragma once

#include <common/game_state.hpp>

#include "pistache/endpoint.h"
#include <pistache/http_defs.h>

#include <iostream>


using namespace Pistache;

struct pokerest : public Http::Handler {
  HTTP_PROTOTYPE(pokerest)
  void onRequest(const Http::Request& request, Http::ResponseWriter writer) override{
    //std::cout<<a.body();
    if (request.resource() == "/common_data" && request.method() == Http::Method::Get) {
        std::stringstream s;
        s<<server::GlobalRoundState;
        writer.send(Http::Code::Ok, s.str());  
    }
    else if (request.resource() == "/1" && request.method() == Http::Method::Post)
            writer.send(Http::Code::Ok, "You posted");
    else if (request.resource() == "/1" && request.method() == Http::Method::Get) 
      writer.send(Http::Code::Ok, "You are player A take your data");
    else if (request.resource() == "/2" && request.method() == Http::Method::Get) 
      writer.send(Http::Code::Ok, "You are player B take your data");
    else if (request.resource() == "/3" && request.method() == Http::Method::Get)
      writer.send(Http::Code::Ok,"You are player C take your data");
    else
      writer.send(Http::Code::Ok, "Not a valid request");
  }
};
