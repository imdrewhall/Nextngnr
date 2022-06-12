import React, { Component } from "react";

export class Gallery extends Component {
  render() {
    return (
      <div id="portfolio" className="text-center">
        <div className="container">
          <div className="section-title">
            <h2>Galería</h2>
            <p>
              ¡Observa una pequeña pizca del trabajo que todos hemos aportado a esta comunidad en crecimiento!
            </p>
          </div>
          <div className="row">
            <div className="portfolio-items">
             {/* Brazo robótico tipo scara                */}
             <div className="col-sm-6 col-md-4 col-lg-4">
                <div className="portfolio-item">
                  <div className="hover-bg">
                    {" "}
                    <a
                      href="img/newportfolio/brazoscara.png"
                      title="Project Title"
                      data-lightbox-gallery="gallery1"
                    >
                      <div className="hover-text">
                        <h4>Brazo robótico tipo scara</h4>
                      </div>
                      <img
                        src="img/newportfolio/brazoscara.png"
                        className="img-responsive"
                        alt="Project Title"
                      />{" "}
                    </a>{" "}
                  </div>
                </div>
              </div>
              {/* Simulador de estacionamientos automatizado */}
              <div className="col-sm-6 col-md-4 col-lg-4">
                <div className="portfolio-item">
                  <div className="hover-bg">
                    {" "}
                    <a
                      href="img/newportfolio/parkinglot.png"
                      title="Project Title"
                      data-lightbox-gallery="gallery1"
                    >
                      <div className="hover-text">
                        <h4>Simulador de estacionamientos automatizado</h4>
                      </div>
                      <img
                        src="img/newportfolio/parkinglot.png"
                        className="img-responsive"
                        alt="Project Title"
                      />{" "}
                    </a>{" "}
                  </div>
                </div>
              </div>
              {/* Sistema de riego controlado por wifi */}
              <div className="col-sm-6 col-md-4 col-lg-4">
                <div className="portfolio-item">
                  <div className="hover-bg">
                    {" "}
                    <a
                      href="img/newportfolio/iotgarden.png"
                      title="Project Title"
                      data-lightbox-gallery="gallery1"
                    >
                      <div className="hover-text">
                        <h4>Sistema de riego controlado por wifi</h4>
                      </div>
                      <img
                        src="img/newportfolio/iotgarden.png"
                        className="img-responsive"
                        alt="Project Title"
                      />{" "}
                    </a>{" "}
                  </div>
                </div>
              </div>
              {/* ESP-32 + Sensor de Ultrasonido + Drivers A4998 */}
              <div className="col-sm-6 col-md-4 col-lg-4">
                <div className="portfolio-item">
                  <div className="hover-bg">
                    {" "}
                    <a
                      href="img/newportfolio/circuitobg3.jpg"
                      title="Project Title"
                      data-lightbox-gallery="gallery1"
                    >
                      <div className="hover-text">
                        <h4>ESP-32 + Sensor de Ultrasonido + Drivers A4998</h4>
                      </div>
                      <img
                        src="img/newportfolio/circuitobg3.jpg"
                        className="img-responsive"
                        alt="Project Title"
                      />{" "}
                    </a>{" "}
                  </div>
                </div>
              </div>
               {/* Control de Nema17 */}
               <div className="col-sm-6 col-md-4 col-lg-4">
                <div className="portfolio-item">
                  <div className="hover-bg">
                    {" "}
                    <a
                      href="img/newportfolio/arduinostep.png"
                      title="Project Title"
                      data-lightbox-gallery="gallery1"
                    >
                      <div className="hover-text">
                        <h4>Control de Nema17</h4>
                      </div>
                      <img
                        src="img/newportfolio/arduinostep.png"
                        className="img-responsive"
                        alt="Project Title"
                      />{" "}
                    </a>{" "}
                  </div>
                </div>
              </div>
              {/* Prueba de Higrómetro (Sensor de humedad) */}
              <div className="col-sm-6 col-md-4 col-lg-4">
                <div className="portfolio-item">
                  <div className="hover-bg">
                    {" "}
                    <a
                      href="img/newportfolio/higro.JPG"
                      title="Project Title"
                      data-lightbox-gallery="gallery1"
                    >
                      <div className="hover-text">
                        <h4>Prueba de Higrómetro (Sensor de humedad)</h4>
                      </div>
                      <img
                        src="img/newportfolio/higro.JPG"
                        className="img-responsive"
                        alt="Project Title"
                      />{" "}
                    </a>{" "}
                  </div>
                </div>
              </div>            
              {/* Circuito controlador de stepper motor para la CNC */}
              <div className="col-sm-6 col-md-4 col-lg-4">
                <div className="portfolio-item">
                  <div className="hover-bg">
                    {" "}
                    <a
                      href="img/newportfolio/controladorstep.png"
                      title="Project Title"
                      data-lightbox-gallery="gallery1"
                    >
                      <div className="hover-text">
                        <h4>Circuito controlador de stepper motor para la CNC</h4>
                      </div>
                      <img
                        src="img/newportfolio/controladorstep.png"
                        className="img-responsive"
                        alt="Project Title"
                      />{" "}
                    </a>{" "}
                  </div>
                </div>
              </div> 
              {/* S.i.a.a.r. */}
              <div className="col-sm-6 col-md-4 col-lg-4">
                <div className="portfolio-item">
                  <div className="hover-bg">
                    {" "}
                    <a
                      href="img/newportfolio/robot.jpg"
                      title="Project Title"
                      data-lightbox-gallery="gallery1"
                    >
                      <div className="hover-text">
                        <h4>S.i.a.a.r.</h4>
                      </div>
                      <img
                        src="img/newportfolio/robot.jpg"
                        className="img-responsive"
                        alt="Project Title"
                      />{" "}
                    </a>{" "}
                  </div>
                </div>
              </div>         
              {/* Mariposas con 3DPrinting */}
              <div className="col-sm-6 col-md-4 col-lg-4">
                <div className="portfolio-item">
                  <div className="hover-bg">
                    {" "}
                    <a
                      href="img/newportfolio/mariposas.jpeg"
                      title="Project Title"
                      data-lightbox-gallery="gallery1"
                    >
                      <div className="hover-text">
                        <h4>Mariposas con 3DPrinting</h4>
                      </div>
                      <img
                        src="img/newportfolio/mariposas.jpeg"
                        className="img-responsive"
                        alt="Project Title"
                      />{" "}
                    </a>{" "}
                  </div>
                </div>
              </div>  
            </div> 
          </div>
        </div>
      </div>
    );
  }
}

export default Gallery;
