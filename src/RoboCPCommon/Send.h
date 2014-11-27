#pragma once
#include <time.h>
#include "Point3d.h"
#include "DisplacementImages.h"

#include <boost/archive/xml_iarchive.hpp>
#include <boost/archive/xml_oarchive.hpp>
#include <boost/serialization/nvp.hpp>
#include <boost/serialization/shared_ptr.hpp>

#include "QtCore\qdatastream.h"

class Send
{

private:
  
	friend class boost::serialization::access;
	
  template<class Archive>
  void serialize(Archive & ar, const unsigned int version) {
	
	ar & BOOST_SERIALIZATION_NVP(TopSonicSensor);
	ar & BOOST_SERIALIZATION_NVP(FrontSonicSensor);
	ar & BOOST_SERIALIZATION_NVP(LeftSonicSensor);
	ar & BOOST_SERIALIZATION_NVP(RightSonicSensor);
	ar & BOOST_SERIALIZATION_NVP(BackSonicSensor);

	ar & BOOST_SERIALIZATION_NVP(Roll);
	ar & BOOST_SERIALIZATION_NVP(Pitch);
	ar & BOOST_SERIALIZATION_NVP(Yaw);
	ar & BOOST_SERIALIZATION_NVP(AltitudeSonic);
	ar & BOOST_SERIALIZATION_NVP(AltitudeBarometer);

	ar & BOOST_SERIALIZATION_NVP(Acceleration);
	ar & BOOST_SERIALIZATION_NVP(PacketType);
    ar & BOOST_SERIALIZATION_NVP(Time);
	ar & BOOST_SERIALIZATION_NVP(Motion);
  }
  
  
  friend QDataStream &operator <<(QDataStream &stream,Send sen)
  {
    stream << sen.TopSonicSensor;
	stream << sen.FrontSonicSensor;
	stream << sen.LeftSonicSensor;
	stream << sen.RightSonicSensor;
	stream << sen.BackSonicSensor;

	stream << sen.Roll;
	stream << sen.Pitch;
	stream << sen.Yaw;
	stream << sen.AltitudeSonic;
	stream << sen.AltitudeBarometer;

	stream << sen.Acceleration;
	stream << sen.PacketType;
    stream << sen.Time;
	stream << sen.Motion;

	return stream;
  }
  
  friend QDataStream &operator >>(QDataStream &stream,Send sen)
  {
    stream >> sen.TopSonicSensor;
	stream >> sen.FrontSonicSensor;
	stream >> sen.LeftSonicSensor;
	stream >> sen.RightSonicSensor;
	stream >> sen.BackSonicSensor;

	stream >> sen.Roll;
	stream >> sen.Pitch;
	stream >> sen.Yaw;
	stream >> sen.AltitudeSonic;
	stream >> sen.AltitudeBarometer;

	stream >> sen.Acceleration;
	stream >> sen.PacketType;
    stream >> sen.Time;
	stream >> sen.Motion;

	return stream;
  }

public:
  unsigned short TopSonicSensor;
  unsigned short FrontSonicSensor;
  unsigned short LeftSonicSensor;
  unsigned short RightSonicSensor;
  unsigned short BackSonicSensor;

  float Roll;
  float Pitch;
  float Yaw;
  float AltitudeSonic;
  float AltitudeBarometer;
  
  Point3d Acceleration;
  int PacketType;
  time_t Time;
  //IplImage *Frame;
  Vector Motion;

  Send(void);
  ~Send(void); 

};

BOOST_SERIALIZATION_SHARED_PTR(Send)