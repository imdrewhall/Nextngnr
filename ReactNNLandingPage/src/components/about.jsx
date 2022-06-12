import React, { Component } from 'react'
import Tilt from 'react-tilt'

export class about extends Component {
  render() {
    return (
        <div id="about">
        <div className="container">
          <div className="row">
            <div className="col-xs-12 col-md-6"> 
            <Tilt className="Tilt" options={{ max : 12 }}  >
              <div className="Tilt-inner"> <img src="img/cursoiotgrey.jpg" className="img-responsive" alt=""/> </div>
              </Tilt> 
             </div>
            <div className="col-xs-12 col-md-6">
              <div className="about-text">
                <h2>Nosotros</h2>
                <p>{this.props.data ? this.props.data.paragraph : 'loading...'}</p>
                <div className="col-lg-6 col-sm-6 col-xs-12">
                  <h3>Misión</h3>
                  <p>{this.props.data ? this.props.data.mision : 'loading...'}</p>
                </div>
                <div className="col-lg-6 col-sm-6 col-xs-12">
                  <h3>Visión</h3>
                  <p>{this.props.data ? this.props.data.vision : 'loading...'}</p>
                </div>
                
               {/*  <h3>¿Por qué escogernos?</h3>
                <div className="list-style">
                  <div className="col-lg-6 col-sm-6 col-xs-12">
                    <ul>
                      {this.props.data ? this.props.data.Why.map((d, i) => <li  key={`${d}-${i}`}>{d}</li>) : 'loading'}
                    </ul>
                  </div>
                  <div className="col-lg-6 col-sm-6 col-xs-12">
                    <ul>
                    {this.props.data ? this.props.data.Why2.map((d, i) => <li  key={`${d}-${i}`}> {d}</li>) : 'loading'}

                    </ul>
                  </div>
                </div> */}
              </div>
            </div>
          </div>
        </div>
      </div>
    )
  }
}

export default about
