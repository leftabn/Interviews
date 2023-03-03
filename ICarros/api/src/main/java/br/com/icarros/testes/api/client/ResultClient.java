package br.com.icarros.testes.api.client;

import feign.Headers;
import org.springframework.cloud.openfeign.FeignClient;
import org.springframework.http.MediaType;
import org.springframework.web.bind.annotation.GetMapping;


@FeignClient(
        name = "consumes",
        url = "${api.ergast.results}"
//        configuration = ResultClient.Configuration.class
)
@Headers(MediaType.APPLICATION_JSON_VALUE)
public interface ResultClient {
//    class Configuration {
//        @Bean
//        public Feign.Builder builder() {
//           return Feign.builder()
//                   .encoder(new Encoder.Default())
//                   .decoder(new Decoder.Default());
//        }
//    }
    @GetMapping("/f1/2017/last/results.json")
    feign.Response getAllResults();
}
