package br.com.icarros.testes.api.service;

import br.com.icarros.testes.api.client.ResultClient;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.List;

@Service
public class ResultService {
    private Logger logger = LoggerFactory.getLogger(this.getClass().getName());
    @Autowired
    private ResultClient client;
    public feign.Response getAllResults() {
        this.logger.info("[getAllResults] - getAllResults request");
        return client.getAllResults();
    }
}
