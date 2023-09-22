#include "Client.h"

int main(int, char**){
    com::example::MeasurementsMessage *msg = new com::example::MeasurementsMessage();
    std::string testStrings = "Hello";
    double test_array[3] = {0.0, 0.0, 0.0};

    msg->mutable_validmeasurementnumber()->set_value(5);
    for(size_t i = 0; i< 5 ; i++)
    {
        com::example::MeasurementsMessage::MeasurementSetMessage *a=msg->add_measurementsset();
        a->mutable_range()->set_value(10.0 + i);
        a->mutable_azimuth()->set_value(10.0 + i);
        a->mutable_elevation()->set_value(10.0 + i);
        a->mutable_elevationvalid()->set_value(true);
        a->mutable_measurementtime()->set_value(10.0 + i);
        a->mutable_radarid()->set_value(10.0 + i);
        a->set_height(10.0 + i);
        a->set_heightvalid(true);
        a->set_rcs(10.0 + i);
        a->mutable_radardimension()->set_value(10 + i);
        a->mutable_plotid()->set_value(10 + i);
        a->set_pd(10.0 + i);
        a->set_pdvalid(true);
        a->set_plottype(10 + i);
        a->set_strength(10 + i);
        a->set_doppler(10.0 + i);
        a->set_dopplervalid(true);
        a->set_snr(10.0 + i);
        a->set_quality(10 + i);
        a->set_qualityvalid(true);
        a->set_source(10 + i);
        a->set_fusionstatus(10 + i);
        a->set_mod1(10 + i);
        a->set_mod2(10 + i);
        a->set_mod3a(10 + i);
        a->set_modc(10 + i);
        a->set_mod4(10 + i);
        a->set_modsaddress(10 + i);
        
        for(char c : testStrings)
        {
            a->add_modscallsign(static_cast<uint32_t>(c));
        }

        a->set_mod5address(10);

        for(char c : testStrings)
        {
            a->add_mod5callsign(static_cast<uint32_t>(c));
        }

        for (int i = 0; i < 3; ++i) {
            a->add_resolution(test_array[i]);
        }

        a->set_resolutionvalid(true);
        a->set_reliability(10.0);
        a->set_reliabilityvalid(true);
    }
    
    std::string dataSender = msg->SerializeAsString();


    cout << "Client is starting...\n";
    boost::asio::io_context io_context;
    TCPClient client(io_context, "127.0.0.1", "55000");  // IP ve portu ayarlayın
    client.setMessage(dataSender);
    // Send and receive fonksiyonunu ayrı bir thread'de çalıştır
    std::thread sendReceiveThread([&client]() {
        client.sendAndReceive();
    });

    io_context.run();
    // Eğer io_context.run() durursa, sendReceiveThread'in de durmasını sağla
    sendReceiveThread.join();

    delete msg;
}
