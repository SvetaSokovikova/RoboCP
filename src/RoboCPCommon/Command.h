#pragma once

#include <boost/archive/xml_iarchive.hpp>
#include <boost/archive/xml_oarchive.hpp>
#include <boost/serialization/nvp.hpp>

#include <time.h>

#include "QtCore\qdatastream.h"

enum CommandType{
  MoveForward,
  Rotate,
  Stay
};

enum CommandCondition{
  PassedTime,
  PassedDistance,
  NearObject
};

class Command {
private:
  
  
	friend class boost::serialization::access;
 
  template<class Archive>
  void serialize(Archive & ar, const unsigned int version) {
	ar & BOOST_SERIALIZATION_NVP(ComType);
	ar & BOOST_SERIALIZATION_NVP(ComCondition);
	ar & BOOST_SERIALIZATION_NVP(Value);
  }
  
  
	friend QDataStream &operator <<(QDataStream &stream,Command com)
  {
  stream << com.ComType;
  stream << com.ComCondition;
  stream << com.Value;
  return stream;
  }

	friend QDataStream &operator >>(QDataStream &stream,Command com)
  {
  stream >> com.ComType;
  stream >> com.ComCondition;
  stream >> com.Value;
  return stream;
  }

public:
  int ComType;
  int ComCondition;
  float Value;
  time_t Time;
  Command (CommandType CType, CommandCondition CCondition, float ConditionValue);
  Command ();
};
