#include "Client.h"

int main(int, char**){
    com::example::MeasurementsMessage msg;
    std::string testStrings = "Hello";
    double test_array[3] = {0.0, 0.0, 0.0};

    msg.mutable_validmeasurementnumber()->set_value(10);
    for(size_t i = 0; i< 5 ; i++)
    {
        com::example::MeasurementsMessage::MeasurementSetMessage *a=msg.add_measurementsset();
        a->mutable_range()->set_value(10.0);
        a->mutable_azimuth()->set_value(10.0);
        a->mutable_elevation()->set_value(10.0);
        a->mutable_elevationvalid()->set_value(true);
        a->mutable_measurementtime()->set_value(10.0);
        a->mutable_radarid()->set_value(10.0);
        a->set_height(10.0);
        a->set_heightvalid(true);
        a->set_rcs(10.0);
        a->mutable_radardimension()->set_value(10);
        a->mutable_plotid()->set_value(10);
        a->set_pd(10.0);
        a->set_pdvalid(true);
        a->set_plottype(10);
        a->set_strength(10);
        a->set_doppler(10.0);
        a->set_dopplervalid(true);
        a->set_snr(10.0);
        a->set_quality(10);
        a->set_qualityvalid(true);
        a->set_source(10);
        a->set_fusionstatus(10);
        a->set_mod1(10);
        a->set_mod2(10);
        a->set_mod3a(10);
        a->set_modc(10);
        a->set_mod4(10);
        a->set_modsaddress(10);
        
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
    
    std::string dataSender = msg.SerializeAsString();
    com::example::MeasurementsMessage msg2;
    std::vector<char> t1(dataSender.begin(),dataSender.end());
    msg2.ParseFromArray(t1.data(),t1.size());
    std::cout<<"msg val = " <<msg2.measurementsset(4).height();

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

}
